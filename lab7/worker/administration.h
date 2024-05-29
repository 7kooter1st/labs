#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "abstract_class.h"

class Administration : public Worker {
public:
    Administration(const char* name_, int age_, int experience_, const char* department) :
        Worker(name_, age_, experience_),
        department(new char[strlen(department) + 1]) {
        strcpy(department, department);
        std::cout << "Administration()" << std::endl;
    }

    ~Administration() {
        delete[] department;
        std::cout << "~Administration()" << std::endl;
    }

    void show() const override {
        std::cout << "Administration: ";
        std::cout << name << ", age: " << age << ", experience: " << experience << ", department: " << department << std::endl;
    }

private:
    char* department;
};

#endif