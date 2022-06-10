#ifndef QUANTIZATIONMETHOD_H
#define QUANTIZATIONMETHOD_H

#include <QList>

#include <color.h>
#include <image.h>

class QuantizationMethod
{
public:
    QuantizationMethod();
    int getColorNum() const;
    void setColorNum(int newColorNum);

    const QList<Color> &getColors() const;

    bool generateColors();

    Image getImage() const;
    void setImage(Image newImage);

protected:
    virtual void process();

    QList<Color> colors;
private:
    int colorNum;
    Image *image;
};

inline uint qHash(const QColor &key)
{
    return (key.red() ^ key.blue() + 47) * key.green();
}

#endif // QUANTIZATIONMETHOD_H
