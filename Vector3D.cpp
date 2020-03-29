#include <iostream>
#include "Vector3D.hpp"


    Vector3D::Vector3D() {}
    Vector3D::Vector3D(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}

    Vector3D::~Vector3D() {}

    Vector3D Vector3D::operator+ (const Vector3D &a) const{
        return Vector3D(x + a.x, y + a.y, z + a.z);
    }
    Vector3D Vector3D::operator- (const Vector3D &a) const{
        return Vector3D(x - a.x, y - a.y, z - a.z);
    }
    double Vector3D::operator* (const Vector3D &a) const{
        return (x * a.x + y * a.y + z * a.z);
    }
    Vector3D Vector3D::operator/ (const double k) const{
        return Vector3D(x / k, y / k, z / k);
    }
    Vector3D Vector3D::operator* (const double k) const{
        return Vector3D(x * k, y * k, z * k);
    }

    Vector3D operator* (double k, const Vector3D& a){
    return a * k;
    }
    std::istream& operator>>(std::istream& is, Vector3D& a){
        is >> a.x >> a.y >> a.z;
        return is;
    }
    std::ostream& operator<<(std::ostream& os, const Vector3D& a) {
        os << a.x << ' ' << a.y << ' ' << a.z;
        return os;
    }
