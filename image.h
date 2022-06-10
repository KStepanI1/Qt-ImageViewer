#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QList>

class Image
{
public:
    Image(const QImage &image);

    QList<QColor> getColors() const;

    int getWidth() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);

private:
    int width;
    int height;
    QList<QColor> colors;
};

#endif // IMAGE_H
