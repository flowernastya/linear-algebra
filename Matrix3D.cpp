#include <iostream>
#include "Vector3D.hpp"
#include "Matrix3D.hpp"

    Matrix3D::Matrix3D(){
        a = new double[9];
        for(int i = 0; i < 9; i++)
            a[i] = 0;
    }
    Matrix3D::Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8){
        a = new double[9];
        a[0] = a0;
        a[1] = a1;
        a[2] = a2;
        a[3] = a3;
        a[4] = a4;
        a[5] = a5;
        a[6] = a6;
        a[7] = a7;
        a[8] = a8;
    }
    Matrix3D::~Matrix3D(){
        delete[] a;
    }

    Matrix3D& Matrix3D::operator+= (const Matrix3D &A) {
        for(int i = 0; i < 9; i++)
            a[i] += *(A.a + i);
        return (*this);
    }
    Matrix3D Matrix3D::operator+ (const Matrix3D &A) const{
        Matrix3D B;
        B += (*this);
        B += A;
        return B;
    }
    Matrix3D Matrix3D::operator- (const Matrix3D &A) const{
        Matrix3D B;
        for(int i = 0; i < 9; i++)
            *(B.a + i) = a[i] - *(A.a + i);
        return B;
    }
    Matrix3D Matrix3D::operator* (const Matrix3D &A) const{
        Matrix3D B;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                    for(int k = 0; k < 3; k++)
                        *(B.a + i * 3 + j) += a[i * 3 + k] * (*(A.a + j + 3 * k));
        return B;
    }
    Matrix3D Matrix3D::operator* (const double k) const{
       Matrix3D B;
       for(int i = 0; i < 9; i++){
            *(B.a + i) = a[i] * k;
       }
       return B;
    }
    Vector3D Matrix3D::operator* (const Vector3D &b) const{
        double d[3];
        for(int i = 0; i < 3; i++){
            Vector3D c = Vector3D(a[3 * i],a[3 * i + 1], a[3 * i + 2]);
            d[i] = b * c;
        }
        return Vector3D(d[0], d[1], d[2]);
    }

    double Matrix3D::det() const{
        return (a[0] * (a[4] * a[8] - a[5] * a[7]) - a[1] * (a[3] * a[8] - a[5] * a[6]) + a[2] *(a[3] * a[7] - a[4] * a[6]));
    }

    Matrix3D operator* (double k, const Matrix3D& a){
    return a * k;
    }

    std::istream& operator>>(std::istream& is, Matrix3D& A){
        for(int i = 0; i < 9; i++)
            is >> *(A.a + i);
        return is;
    }
    std::ostream& operator<<(std::ostream& os, const Matrix3D& A) {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
                os << *(A.a + i * 3 + j) << ' ';
            os << "\n";
        }
        return os;
    }
