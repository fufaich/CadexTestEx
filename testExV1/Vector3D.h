#pragma once
class Vector3D
{
private:
	double x, y, z;
public:
	Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
	double getX() const { return x; }
	double getY() const { return y; }
	double getZ() const { return z; }

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D operator*(float scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

};

