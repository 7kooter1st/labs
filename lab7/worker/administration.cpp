#include "administration.h"

void Administration::show() const {
    std::cout << "Администрация: \n";
    std::cout << name << ", возраст: " << age << ", опыт: " << experience << ", отделение: " << department << std::endl;
    }

void Administration::clear() const {
    delete[] department;
}

void Administration::remove() const {
    delete[] department;
}