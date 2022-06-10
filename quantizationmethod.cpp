#include "quantizationmethod.h"

#include <QMap>
#include <QHash>

QuantizationMethod::QuantizationMethod():
    colorNum(8), image()
{

}

void QuantizationMethod::process()
{
    QHash<QColor, long long> colorCountMap;
    for (QColor &color : image->getColors())
    {
        colorCountMap[color]++;
    }

    QMap<long long, QColor> sortColorsByValueMap;
    for (auto i = colorCountMap.begin(); i != colorCountMap.end(); ++i)
    {
        sortColorsByValueMap.insert(i.value(), i.key());
    }

    auto colorList = sortColorsByValueMap.values();
    colors.clear();
    for (auto i = colorList.rbegin(); i != colorList.rend(); ++i)
    {
        if (colors.size() == colorNum)
        {
            break;
        }
        else
        {
            colors.push_back(Color(*i, 0));
        }
    }
}

int QuantizationMethod::getColorNum() const
{
    return colorNum;
}

void QuantizationMethod::setColorNum(int newColorNum)
{
    colorNum = newColorNum;
}

const QList<Color> &QuantizationMethod::getColors() const
{
    return colors;
}

bool QuantizationMethod::generateColors()
{
    if (!image || colorNum == 0)
    {
        return false;
    }
    colors.clear();
    process();
    return true;
}

Image QuantizationMethod::getImage() const
{
    return *image;
}

void QuantizationMethod::setImage(Image newImage)
{
    image = new Image(newImage);
}
