#ifndef TERM_H
#define TERM_H

#define MAX_NAME 100

#include "Vector.h"
#include <iostream>

class Term {
private:
    int coefficient;
    int exponent;

public:
    Term() : coefficient(0), exponent(0) {}
    Term(int coef, int exp) : coefficient(coef), exponent(exp) {}

    int getCoefficient() const { return coefficient; }
    int getExponent() const { return exponent; }

    Term operator+(const Term& other) const {
        if (exponent != other.exponent)
            throw std::invalid_argument("степени должны быть одинаковыми");
        return Term(coefficient + other.coefficient, exponent);
    }
    int pow(int a, int b);
    friend std::ostream& operator<<(std::ostream& out, const Term& term);
    friend std::istream& operator>>(std::istream& in, Term& term);

    Term operator=(const Term& other) {
        coefficient = other.coefficient;
        exponent = other.exponent;
        return *this;
    }
    bool operator==(const Term& other) const {
        if (exponent == other.exponent) {
            return true;
        }
        return false;
    }
};

int Term::pow(int a, int b) {
    int n = 1;
    for (int i = 0; i < b; i++) {
        n *= a;
    }
    return n;
}

std::ostream& operator<<(std::ostream& out, const Term& term) {
    if (term.exponent == 0) {
        out << term.coefficient;
    }
    else if (term.exponent == 1) {
        out << term.coefficient << "x";
    }
    else {
        out << term.coefficient << "x^" << term.exponent;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Term& term) {
    char name[MAX_NAME] = "";
    std::cin.getline(name, MAX_NAME);
    char* coef = strtok(name, "x");
    char cef[MAX_NAME] = "";
    strcpy(cef, coef);
    double sum = 0;
    for (int i = 0; i < strlen(cef); i++) {
        sum += (int(cef[i]) - 48) * pow(10, strlen(cef) - i - 1);
    }
    if (cef[0] == '-') {
        sum -= (int(cef[0]) - 48) * pow(10, strlen(cef) - 0 - 1);
        sum *= -1;
    }
    term.coefficient = sum;
    sum = 0;
    coef = strtok(NULL, "x");
    strcpy(cef, coef);
    for (int i = 0; i < strlen(cef); i++) {
        sum += (int(cef[i]) - 48) * pow(10, strlen(cef) - i - 1);
    }
    if (cef[0] == '-') {
        sum -= (int(cef[0]) - 48) * pow(10, strlen(cef) - 0 - 1);
        sum *= -1;
    }
    term.exponent = sum;
    return in;
}

#endif