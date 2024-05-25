#ifndef UNTITLED60_FRACTION_H
#define UNTITLED60_FRACTION_H
#define MAX_NAME 100

#include <iostream>
#include <fstream>
#include <vector>

class fraction {
private:
    int num_;
    int den_;
public:
    explicit fraction(int n = 0, int d = 1) : num_(n), den_(d) {}
    fraction(char*);
    fraction(double);
    ~fraction();

    int pow(int, int);
    void SetFract(char*);

    /*fraction operator+(const fraction& f) const;
    fraction operator+=(const fraction& f) const;*/
    fraction operator-(const fraction& f) const;
    fraction operator*(const fraction& f) const;
    fraction operator/(const fraction& f) const;

    int GetNum() { return num_; }
    int GetDen() { return den_; }
    void SetNum(int num) { num_ = num; }
    void SetDen(int den) { den_ = den; }
    int WholePart() const { return num_ / den_; }
};
void operator+=(fraction&, fraction&);
void operator+=(fraction&, int&);
void operator+=(fraction&, double&);

fraction operator+(fraction&, fraction&);
fraction operator+(fraction&, int&);
fraction operator+(fraction&, double&);

std::istream& operator>>(std::istream&, fraction&);

std::ostream& operator<<(std::ostream&, fraction&);

void GetFract(char*, fraction**&);

void print(fraction**&);

int GCD(int, int);

#endif
