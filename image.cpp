#include "image.h"


Image::Image(const QImage &image)
{
    for (int x = 0; x != image.width(); ++x)
    {
        for (int y = 0; y != image.height(); ++y)
        {
            QColor color = image.pixelColor(x, y);
            colors.push_back(color);
        }
    }
}

QList<QColor> Image::getColors() const
{
    return colors;
}

int Image::getWidth() const
{
    return width;
}

void Image::setWidth(int newWidth)
{
    width = newWidth;
}

int Image::getHeight() const
{
    return height;
}

void Image::setHeight(int newHeight)
{
    height = newHeight;
}
