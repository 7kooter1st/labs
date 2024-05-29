#ifndef ABSTRACT_CLASS_H
#define ABSTRACT_CLASS_H

#include <iostream>

class Worker {
protected:
    char* name;  
    int age;     
    int experience; 

public:
    Worker(const char* name_, int age_, int experience_) :
        name(new char[strlen(name_) + 1]),
        age(age_),
        experience(experience_) {
        strcpy(name, name_);
        std::cout << "Worker()" << std::endl;
    }

    virtual ~Worker() {
        delete[] name;
        std::cout << "~Worker()" << std::endl;
    }

    virtual void show() const = 0;
};

#endif