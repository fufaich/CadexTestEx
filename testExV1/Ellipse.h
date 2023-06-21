#pragma once
#include "Curve.h"
#include <math.h>
#include <iostream>

class Ellipse :
    public Curve
{
private:
    double radiusAlongX;
    double radiusAlongY;
public:

    Ellipse(double radiusValueX, double radiusValueY) :radiusAlongX(radiusValueX), radiusAlongY(radiusValueY) {}
    double getRadius() const { return (radiusAlongX + radiusAlongY) / 2; };
    Vector3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;
    void printCoordinatesAndDerivative(double t) const override;
};

