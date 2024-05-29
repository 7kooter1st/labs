#include "Polinom/Polinomial.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    Polynomial poly1;
    Polynomial poly2;
    Term term1(3, 2);
    Term term2(-1, 2);
    Term term3(5, 5);

    poly1.addTerm(term1);
    poly1.addTerm(term2);
    poly1.addTerm(term3);

    std::cout << "Полином 1:" << poly1 << std::endl;

    std::cout << "Введите второй полином:\n";
    std::cin >> poly2;
    std::cout << "Полином2 2: " << poly2 << std::endl;

    Polynomial poly3 = poly1 + poly2;
    std::cout << "сумма полиномов" << poly3 << std::endl;

    return 0;
}