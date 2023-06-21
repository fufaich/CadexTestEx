#pragma once
#include "Vector3D.h"
class Curve {
public:
	virtual double getRadius() const = 0;

	virtual Vector3D getPoint(double t) const = 0;

	virtual Vector3D getDerivative(double t) const = 0;
	virtual void printCoordinatesAndDerivative(double t) const = 0;
};