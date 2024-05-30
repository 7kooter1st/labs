#ifndef ENGINEER_H
#define ENGINEER_H

#include "abstract_class.h"

class Engineer : public Worker {
private:
    char* specialization;
public:
    Engineer(const char* name_, int age_, int experience_, const char* specialization_) :
        Worker(name_, age_, experience_) {
        if (specialization_ != nullptr) {
            specialization = new char[strlen(specialization_) + 1];
            strcpy(specialization, specialization_);
        }
        else {
            specialization = nullptr;
        }
    }

    ~Engineer() {
        delete[] specialization;
    }

    void show() const override;

    void clear() const override;

    void remove() const override;


};

#endif