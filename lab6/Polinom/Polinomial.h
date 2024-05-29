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
        terms.add_element(term);
    }


    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        for (int i = 0; i < other.terms.GetSize(); ++i) {
            result.addTerm(other.terms[i]);
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result;
        for (int i = 0; i < other.terms.GetSize(); ++i) {
            for (int j = 0; j < (*this).terms.GetSize(); j++) {
                if (other.terms[i] == (*this).terms[j]) {
                    result.addTerm(other.terms[i]);
                }
            }
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
    char ch;
    int coef = 0, exp = 0, sign = 1;
    while (in.get(ch)) {
        if (isspace(ch)) {
            continue;
        }
        else if (isdigit(ch)) {
            coef = coef * 10 + (ch - '0');
        }
        else if (ch == '+' || ch == '-') {
            if (coef != 0) {
                poly.addTerm(Term(coef * sign, exp));
                coef = 0;
                exp = 0;
            }
            sign = (ch == '+') ? 1 : -1;
        }
        else if (ch == 'x') {
            if (coef == 0) {
                coef = 1;
            }
            if (in.peek() == '^') {
                in.get(ch);
                in.get(ch);
                exp = (ch - '0');
                while (in.peek() >= '0' && in.peek() <= '9') {
                    in.get(ch);
                    exp = exp * 10 + (ch - '0');
                }
            }
            else {
                exp = 1;
            }
        }
        else {
            break;
        }
    }

    if (coef != 0) {
        poly.addTerm(Term(coef * sign, exp));
    }

    return in;
}

//in.getline(input, 1000);
//char stroka[1000];
//for (int i = 0; i < strlen(input); i++) {
//    if (input[i] != " ")
//        str
//}

#endif
