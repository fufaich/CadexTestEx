#pragma once
#include "Curve.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES // for C++


class Helix :
    public Curve
{
private:
    double radius;
    double step;
public:
    Helix(double radiusValue, double stepValue) : radius(radiusValue), step(stepValue) {}
    double getRadius() const { return radius; };

    Vector3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;
    void printCoordinatesAndDerivative(double t) const override;
};

