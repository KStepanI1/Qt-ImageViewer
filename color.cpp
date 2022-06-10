#include "color.h"

Color::Color(const int &r, const int &g, const int &b, const double &percentage):
    color(r, g, b), percentage(percentage)
{
}

Color::Color(const QColor &color, const double &percentage):
    color(color), percentage(percentage)
{

}

QString Color::getName()
{
    return "";
}

double Color::getPercentage() const
{
    return percentage;
}

QColor Color::getColor() const
{
    return color;
}
