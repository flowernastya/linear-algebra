#include <iostream>

class Vector3D{
    double x, y, z;
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& a);
    friend std::istream& operator>>(std::istream &is, Vector3D &a);
    //friend Vector3D operator* (const Vector3D &b) const;
public:
    Vector3D() {}
    Vector3D(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
    ~Vector3D() {}
    Vector3D operator+ (const Vector3D &a) const{
        return Vector3D(x + a.x, y + a.y, z + a.z);
    }
    Vector3D operator- (const Vector3D &a) const{
        return Vector3D(x - a.x, y - a.y, z - a.z);
    }
   /* long double length() const{
        return sqrt(x * x + y * y + z * z);
    }*/
    double operator* (const Vector3D &a) const{
        return (x * a.x + y * a.y + z * a.z);
    }
    Vector3D operator/ (const double k) const{
        return Vector3D(x / k, y / k, z / k);
    }
    Vector3D operator* (const double k) const{
        return Vector3D(x * k, y * k, z * k);
    }

};
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
class Matrix3D{
    double *a;
    friend std::ostream& operator<<(std::ostream& os, const Matrix3D& A);
    friend std::istream& operator>>(std::istream &is, Matrix3D &A);
public:
    Matrix3D(){
        a = new double[9];
        for(int i = 0; i < 9; i++)
            a[i] = 0;
    }
    Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8){
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
    ~Matrix3D(){
        delete[] a;
    }
    Matrix3D& operator+= (const Matrix3D &A) {
        for(int i = 0; i < 9; i++)
            a[i] += *(A.a + i);
        return (*this);
    }
    Matrix3D operator+ (const Matrix3D &A) const{
        Matrix3D B;
        B += (*this);
        B += A;
        return B;
    }
    Matrix3D operator- (const Matrix3D &A) const{
        Matrix3D B;
        for(int i = 0; i < 9; i++)
            *(B.a + i) = a[i] - *(A.a + i);
        return B;
    }
    Matrix3D operator* (const Matrix3D &A) const{
        Matrix3D B;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                    for(int k = 0; k < 3; k++)
                        *(B.a + i * 3 + j) += a[i * 3 + k] * (*(A.a + j + 3 * k));
        return B;
    }
    Matrix3D operator* (const double k) const{
       Matrix3D B;
       for(int i = 0; i < 9; i++){
            *(B.a + i) = a[i] * k;
       }
       return B;
    }
    Vector3D operator* (const Vector3D &b) const{
        double d[3];
        for(int i = 0; i < 3; i++){
            Vector3D c = Vector3D(a[3 * i],a[3 * i + 1], a[3 * i + 2]);
            d[i] = b * c;
        }
        return Vector3D(d[0], d[1], d[2]);
    }
    double det() const{
        return (a[0] * (a[4] * a[8] - a[5] * a[7]) - a[1] * (a[3] * a[8] - a[5] * a[6]) + a[2] *(a[3] * a[7] - a[4] * a[6]));
    }
};
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
int main()
{
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
    std::cin >> B;

    // Базовые операции с векторами
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * 3 = " << A * 3 << std::endl;
    std::cout << "2 * B = " << 2 * B << std::endl;
    std::cout << "A + B = " << A + B << std::endl;
    std::cout << "A - B = " << A - B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;

    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
    Matrix3D D;
    std::cin >> D;

    // Базовые операции с матрицами
    std::cout << "C = " << C << std::endl;
    std::cout << "D = " << D << std::endl;
    std::cout << "C * 3 = " << C * 3 << std::endl;
    std::cout << "2 * D = " << 2 * D << std::endl;
    std::cout << "C + D = " << C + D << std::endl;
    std::cout << "C - D = " << C - D << std::endl;
    std::cout << "C * D = " << C * D << std::endl;

    // Детерминант матрицы
    std::cout << "det(D) = " << D.det() << std::endl;

    // Умножение матрицы на вектор
    std::cout << "D * B = " << D * B << std::endl;
    return 0;
}
