#ifndef HR_H
#define HR_H

#include "abstract_class.h"

class HR : public Worker {
public:
    HR(const char* name_, int age_, int experience_, int num_employees) :
        Worker(name_, age_, experience_),
        num_employees(num_employees) {
    }

    ~HR() {
    }

    void show() const override {
        std::cout << "HR: ";
        std::cout << name << ", возраст: " << age << ", опыт: " << experience << ", количество работников : " << num_employees << std::endl;
    }

    void clear() const override {
    }

    void remove() const override {
    }

private:
    int num_employees;
};

#endif