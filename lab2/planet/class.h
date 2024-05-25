#define PLANET_H
#define MAX_NAME 100
 
#include <iostream>
#include <fstream>
#include <vector>

class planet{
private:
    char* name_;
    unsigned int diameter_;
    bool life_;
    unsigned int satelite_;
public:
    planet();
    planet(char* name, unsigned int diameter, bool life, unsigned int satelite);
    ~planet();
    void SetName(char* name);
    void SetDiameter(unsigned diameter);
    void SetLife(bool life);
    void SetSatelite(unsigned int satelite);
    char* GetName();
    unsigned int GetDiameter();
    bool GetLife();
    unsigned int GetSatelite();
};

planet* read_db(char*, planet**&, unsigned int&);

int menu();

void print_db(planet**&, unsigned int&);

planet* write_db(char*, planet**&, unsigned int&);

unsigned int find(planet**&, unsigned int&);

void sort_db(planet**&, unsigned int&);

void resize(planet**&, unsigned int&, unsigned int&);

void add(planet**&, unsigned int&);

int del(planet**&, unsigned int&);

int start_planet();