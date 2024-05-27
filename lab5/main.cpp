#include <iostream>
#include <cstring>
#include "VectorSet/Myset.h"

int main() {
    setlocale(LC_ALL, "Russian");
    MySet<int> a;
    a.add_element(1);
    a.add_element(4);
    a.add_element(8);
    MySet<int> b;
    b.add_element(3);
    b.add_element(12);
    b.add_element(7);
    MySet<int> c(a);
    c += b;
    MySet<int> sum;
    sum = a + b;

    return 0;
}
