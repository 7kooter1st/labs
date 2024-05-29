#ifndef HR_H
#define HR_H

#include "abstract_class.h"

class HR : public Worker {
public:
    HR(const char* name_, int age_, int experience_, int num_employees) :
        Worker(name_, age_, experience_),
        num_employees(num_employees) {
        std::cout << "HR()" << std::endl;
    }

    ~HR() {
        std::cout << "~HR()" << std::endl;
    }

    void show() const override {
        std::cout << "HR: ";
        std::cout << name << ", age: " << age << ", experience: " << experience << ", number of employees: " << num_employees << std::endl;
    }

private:
    int num_employees;
};

#endif