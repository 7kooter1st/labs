#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Vector.h"
#include "Term.h"

class Polynomial {
private:
    MyVector<Term> terms;

public:
    Polynomial() {}
    Polynomial(const Term& term) { terms.add_element(term); }

    void addTerm(const Term& term) {
        for (int i = 0; i < terms.GetSize(); ++i) {
            if (term.getExponent() == terms[i].getExponent()) {
                terms[i] = terms[i] + term;
                return;
            }
        }
        terms.add_element(term);
    }


    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        for (int i = 0; i < other.terms.GetSize(); ++i) {
            result.addTerm(other.terms[i]);
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly);
    friend std::istream& operator>>(std::istream& in, Polynomial& poly);
};

std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
    for (int i = 0; i < poly.terms.GetSize(); ++i) {
        out << poly.terms[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Polynomial& poly) {
    int coef, exp;
    char input[100];
    while (in.getline(input, 100)) {
        if (sscanf(input, "%d x^%d", &coef, &exp) == 2) {
            poly.addTerm(Term(coef, exp));
        }
        else if (sscanf(input, "%d x", &coef) == 1) {
            poly.addTerm(Term(coef, 1));
        }
        else if (sscanf(input, "%d", &coef) == 1) {
            poly.addTerm(Term(coef, 0));
        }
    }
    return in;
}

#endif
