#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "abstract_class.h"

class Administration : public Worker {
private:
    char* department;
public:
    Administration(const char* name_, int age_, int experience_, const char* department_) :
        Worker(name_, age_, experience_),
        department(new char[strlen(department_) + 1]) {
        strcpy(department, department_);
    }

    ~Administration() {
        delete[] department;
    }

    void show() const override;

    void clear() const override;

    void remove() const override;
};

#endif