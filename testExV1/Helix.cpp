#include "Helix.h"
#define _USE_MATH_DEFINES
#include<cmath>
const double M_PI = std::acos(-1.0);

Vector3D Helix::getPoint(double t) const
{
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = step * t;
    return Vector3D(x,y,z);
}

Vector3D Helix::getDerivative(double t) const
{
    double dx_dt = -radius * sin(t);
    double dy_dt = radius * cos(t);
    double dz_dt = step;

    return Vector3D(dx_dt,dy_dt,dz_dt);
}

void Helix::printCoordinatesAndDerivative(double t) const
{
    auto Coord = getPoint(t);
    auto Deriv = getDerivative(t);
    std::cout << "Coordinates at t = " << t << " :( " << Coord.getX() << ", " << Coord.getY() << " ," << Coord.getZ() << " )" << std::endl;
    std::cout << "Derivative at t = " << t << " :( " << Deriv.getX() << ", " << Deriv.getY() << " ," << Deriv.getZ() << " )" << std::endl;
}
