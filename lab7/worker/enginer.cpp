#include "enginer.h"

void Engineer::show() const {
    std::cout << "�������: ";
    std::cout << name << ", �������: " << age << ", ����: " << experience << ", �������������: " << specialization << std::endl;
}

void Engineer::clear() const {
    delete[] specialization;
}

void Engineer::remove() const {
    delete[] specialization;
}