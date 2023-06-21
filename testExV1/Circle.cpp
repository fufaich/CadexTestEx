#include "Circle.h"

Vector3D Circle::getPoint(double t) const
{
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = 0.0;
    return Vector3D(x,y,z);
}

Vector3D Circle::getDerivative(double t) const
{
    double dx_dt = radius *  ( - 1 * sin(t));
    double dy_dt = radius * cos(t);
    double dz_dt = 0.0;

    return Vector3D(dx_dt, dy_dt, dz_dt);
}

void Circle::printCoordinatesAndDerivative(double t)const
{
    auto Coord = getPoint(t);
    auto Deriv = getDerivative(t);
    std::cout << "Coordinates at t = " << t << " :( " << Coord.getX() << ", " << Coord.getY() << " ," << Coord.getZ() << " )" << std::endl;
    std::cout << "Derivative at t = " << t << " :( " << Deriv.getX() << ", " << Deriv.getY() << " ," << Deriv.getZ() << " )" << std::endl;
}
