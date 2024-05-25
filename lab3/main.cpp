#include <iostream>
#include <iomanip>
#include "out\fraction\fraction.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // ���� ����� � ����������
    std::cout << "������� �����: \n";
    fraction z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;
    // �������� �������������
    fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    fraction f = dbl;
    std::cout << "f=" << f << std::endl;
    // �������� ������������� �������� "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = y + dbl;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += x + dbl + i;
    std::cout << "y=" << y << std::endl;
    return 0;
}