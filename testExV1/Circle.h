#pragma once
#include "Curve.h"
#include <math.h>
#include <iostream>

class Circle :
    public Curve
{
private:
    double radius;
public:
    Circle(double radiusValue) :radius(radiusValue) {}
    double getRadius() const { return radius; };

    Vector3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;
    void printCoordinatesAndDerivative(double t) const override;
};

