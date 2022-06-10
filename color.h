#ifndef COLOR_H
#define COLOR_H

#include <QString>
#include <QColor>

class Color
{
public:
    Color(const int &r, const int &g, const int &b, const double &percentage);
    Color(const QColor &color, const double &percentage);
    QString getName();
    double getPercentage() const;
    QColor getColor() const;


private:
    QColor color;
    double percentage;
};

#endif // COLOR_H
