#pragma once


#include <QtWidgets/QGraphicsScene>

class QGraphicsSceneMouseEvent;
class QGraphicsPixmapItem;
class QGraphicsRectItem;

class ClipScene : public QGraphicsScene
{
    Q_OBJECT
    Q_PROPERTY(QPointF previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)

public:
    ClipScene(QObject* parent);
    QPointF previousPosition() const;
    void setImage(const QImage img);

signals:
    void previousPositionChanged(const QPointF previousPosition);
    void clippedImage(const QPixmap& pixmap);

public slots:
    void setPreviousPosition(const QPointF previousPosition);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;


private:
    QGraphicsRectItem* m_selection          {nullptr};
    QGraphicsPixmapItem* m_currentImageItem {nullptr};
    QPointF m_previousPosition;
    bool m_leftMouseButtonPressed           {false};
};
