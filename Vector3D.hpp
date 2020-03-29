#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector3D{
    double x, y, z;
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& a);
    friend std::istream& operator>>(std::istream &is, Vector3D &a);
public:
    Vector3D();

    Vector3D(double _x, double _y, double _z);

    ~Vector3D();

    Vector3D operator+ (const Vector3D &a) const;

    Vector3D operator- (const Vector3D &a) const;

    double operator* (const Vector3D &a) const;

    Vector3D operator/ (const double k) const;

    Vector3D operator* (const double k) const;
};
Vector3D operator* (double k, const Vector3D& a);
std::istream& operator>>(std::istream& is, Vector3D& a);
std::ostream& operator<<(std::ostream& os, const Vector3D& a);
#endif // VECTOR_H

