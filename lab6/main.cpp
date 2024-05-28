#include "Polinom/Polinomial.h"
#include <iostream>

int main() {
    Polynomial poly1;
    Polynomial poly2;
    Term term1(3, 2);
    Term term2(-1, 2);
    Term term3(5, 5);

    poly1.addTerm(term1);
    poly1.addTerm(term2);
    poly1.addTerm(term3);

    std::cout << "Polynomial 1: " << poly1 << std::endl;

    std::cout << "Enter polynomial 2 (e.g., 3x^2 - x^2 + 5x^5): ";
    std::cin >> poly2;
    std::cout << "Polynomial 2: " << poly2 << std::endl;

    Polynomial poly3 = poly1 + poly2;
    std::cout << "Sum of polynomials: " << poly3 << std::endl;

    return 0;
}