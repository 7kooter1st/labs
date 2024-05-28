#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include "Vector.h"

class worker {
protected:
    static MyVector<worker*> objects;

public:
    worker() {
        objects.add_element(this);
    }

    virtual ~worker() {}

    virtual void Show() = 0;

    static void Print() {
        for (int i = 0; i < objects.GetSize();i++) {
            objects[i]->Show();
        }
    }
};

MyVector<worker*> worker::objects;

class personnel : public worker {
private:
    char* name;
    int salary;

public:
    personnel(char*& name, int& salary) : worker(), name(name), salary(salary) {}

    void Show() override {
        std::cout << "name: " << name << std::endl;
        std::cout << "salary: " << salary << std::endl;
    }
};

class engineer : public personnel {

protected:
    std::string country;
    std::string king;
public:
    engineer(const std::string& country, const std::string& king) : worker(), country(country), king(king) {}

    void Show() override {
        std::cout << "engineer: " << country << std::endl;
        std::cout << "King: " << king << std::endl;
    }
};

class Kingdom : public engineer {
public:
    Kingdom(const std::string& country, const std::string& king) : engineer(country, king) {}

    void Show() override {
        std::cout << "Kingdom: " << country << std::endl;
        std::cout << "King: " << king << std::endl;
    }
};

#endif
