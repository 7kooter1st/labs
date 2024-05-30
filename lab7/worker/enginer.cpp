#include "enginer.h"

void Engineer::show() const {
    std::cout << "Инженер: ";
    std::cout << name << ", возраст: " << age << ", опыт: " << experience << ", специализация: " << specialization << std::endl;
}

void Engineer::clear() const {
    delete[] specialization;
}

void Engineer::remove() const {
    delete[] specialization;
}