#ifndef CUTDIALOG_H
#define CUTDIALOG_H

#include <QDialog>
#include <QtWidgets/QWidget>

class QGridLayout;
class QPushButton;
class QGraphicsView;
class QLabel;
class ClipScene;

namespace Ui {
class CutDialog;
}

class CutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CutDialog(QWidget *parent = nullptr);
    ~CutDialog();

private:
    Ui::CutDialog *ui;
    QGridLayout* m_gridLayout;
    QPushButton* m_pushButton;
    QGraphicsView* m_graphicsView;
    QLabel* m_clippedLabel;         // Лейбл, в который будет помещаться обрезанное изображение
    ClipScene* m_clipScene;         // Графическая сцена в которой реализован функционал по обрезке изображения
    QString imagePath;
    QImage view;

    void onSaveClicked();
public slots:
    void slot(const QPixmap *pix);                           // Слот добавления изображения в приложение
    void onClippedImage(const QPixmap& pixmap); // Слот принимающий обрезанную область приложения

signals:
    void signalCut(QImage img);
};

#endif // CUTDIALOG_H
