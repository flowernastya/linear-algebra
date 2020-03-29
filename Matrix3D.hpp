#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector3D.hpp"
class Matrix3D{
    double *a;
    friend std::ostream& operator<<(std::ostream& os, const Matrix3D& A);
    friend std::istream& operator>>(std::istream &is, Matrix3D &A);
public:
    Matrix3D();
    Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8);
    ~Matrix3D();

    Matrix3D& operator+= (const Matrix3D &A);
    Matrix3D operator+ (const Matrix3D &A) const;
    Matrix3D operator- (const Matrix3D &A) const;

    Matrix3D operator* (const Matrix3D &A) const;
    Matrix3D operator* (const double k) const;
    Vector3D operator* (const Vector3D &b) const;

    double det() const;
};
Matrix3D operator* (double k, const Matrix3D& a);

std::istream& operator>>(std::istream& is, Matrix3D& A);
std::ostream& operator<<(std::ostream& os, const Matrix3D& A);
#endif // MATRIX_H
