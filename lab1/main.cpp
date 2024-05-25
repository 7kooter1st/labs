#include <iostream>
#include "mymath/mymath.h"
#include "fan/fan.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 10+32=";
    std::cout << mymath::sum(10, 32) << std::endl;
    std::cout << fan::fan(1000);
    return 0;
}