#ifndef ENGINEER_H
#define ENGINEER_H

#include "abstract_class.h"

class Engineer : public Worker {
public:
    Engineer(const char* name_, int age_, int experience_, const char* specialization) :
        Worker(name_, age_, experience_),
        specialization(new char[strlen(specialization) + 1]) {
        strcpy(specialization, specialization);
        std::cout << "Engineer()" << std::endl;
    }

    ~Engineer() {
        delete[] specialization;
        std::cout << "~Engineer()" << std::endl;
    }

    void show() const override {
        std::cout << "Engineer: ";
        std::cout << name << ", age: " << age << ", experience: " << experience << ", specialization: " << specialization << std::endl;
    }

private:
    char* specialization;
};

#endif