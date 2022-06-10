#include "kmeansmethod.h"

#include <qrandom.h>

KMeansMethod::KMeansMethod()
{

}


void KMeansMethod::process()
{
    QVector<QColor> pointsColor;
    QVector<int> pointsK(getImage().getColors().size());

    for (const QColor &color: getImage().getColors())
    {
        pointsColor.push_back(color);
    }

    QRandomGenerator random;
    QVector<QColor> kSet(getColorNum()), oldKSet;
    QVector<long> kSetCount(getColorNum());

    for(auto &k: kSet)
    {
        k = pointsColor[random.generate() % getImage().getColors().size()];
    }

    while (kSet != oldKSet)
    {

        for (int i = 0; i < pointsColor.size(); i++)
        {
            int distanceSquared = std::numeric_limits<int>::max();
            for (int j = 0; j < kSet.size(); j++)
            {
                int dr = kSet[j].red() - pointsColor[i].red();
                int dg = kSet[j].green() - pointsColor[i].green();
                int db = kSet[j].blue() - pointsColor[i].blue();
                int newDistance = dr * dr + dg * dg + db * db;

                if (newDistance < distanceSquared)
                {
                    pointsK[i] = j;
                    distanceSquared = newDistance;
                }
            }
        }

        oldKSet = kSet;

        for (int i = 0; i < kSet.size(); i++)
        {
            int count = 0, r = 0, g = 0, b = 0;

            for (int j = 0; j < pointsColor.size(); j++)
            {
                if (i == pointsK[j])
                {
                    count++;
                    r += pointsColor[j].red();
                    g += pointsColor[j].green();
                    b += pointsColor[j].blue();
                }
            }

            if (count > 0)
            {
                kSet[i].setRed(r / count);
                kSet[i].setGreen(g / count);
                kSet[i].setBlue(b / count);
            }

        }
    }

    for (int i = 0; i < pointsColor.size(); i++)
    {
        kSetCount[pointsK[i]]++;
    }

    for (int i = 0; i < kSet.size(); i++)
    {
        colors.push_back(Color(kSet[i].red(), kSet[i].green(), kSet[i].blue(), kSetCount[i] / static_cast<double>(pointsColor.size())));
    }


}
