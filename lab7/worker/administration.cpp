#include "administration.h"

void Administration::show() const {
    std::cout << "�������������: \n";
    std::cout << name << ", �������: " << age << ", ����: " << experience << ", ���������: " << department << std::endl;
    }

void Administration::clear() const {
    delete[] department;
}

void Administration::remove() const {
    delete[] department;
}