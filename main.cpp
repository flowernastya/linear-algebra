#include <iostream>
#include "Vector3D.hpp"
#include "Matrix3D.hpp"

int main()
{
    // ������ ����� � ����
    Vector3D A(1, 2, 3);
    // ������ �������� �� cin
    Vector3D B;
    std::cin >> B;

    // ������� �������� � ���������
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "A * 3 = " << A * 3 << std::endl;
    std::cout << "2 * B = " << 2 * B << std::endl;
    std::cout << "A + B = " << A + B << std::endl;
    std::cout << "A - B = " << A - B << std::endl;
    std::cout << "A * B = " << A * B << std::endl;

    // ������� ������ � ����
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // ������� �������� �� cin
    Matrix3D D;
    std::cin >> D;

    // ������� �������� � ���������
    std::cout << "C = " << C << std::endl;
    std::cout << "D = " << D << std::endl;
    std::cout << "C * 3 = " << C * 3 << std::endl;
    std::cout << "2 * D = " << 2 * D << std::endl;
    std::cout << "C + D = " << C + D << std::endl;
    std::cout << "C - D = " << C - D << std::endl;
    std::cout << "C * D = " << C * D << std::endl;

    // ����������� �������
    std::cout << "det(D) = " << D.det() << std::endl;

    // ��������� ������� �� ������
    std::cout << "D * B = " << D * B << std::endl;
    return 0;
}
