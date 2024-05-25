#include <iostream>
#include <cstring>
#include "Mystack/MyStack.h"

//double pow(double one, double two) {
//    int result = 1;
//    for (int i = 0; i < two; i++) {
//        result *= one;
//    }
//    return result;
//}

void Multipliers(int num, MyStack<int>& stack) {
        int den = 1;
        int l = num;
        while (num > den) {
            int i = 2;
            for (; l % i != 0; i++);
            stack.push(i);
            l /= i;
            den *= i;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    MyStack<int> stack;
    MyStack<int> help;
    int example = 3960;
    Multipliers(example, stack);
    std::cout << "\nразложение на простые множители числа по возрастанию\n" << example << ":";
    /*print(stack, "* ");*/
    while (true) {
        std::cout << stack.top_inf();
        help.push(stack.top_inf());
        stack.pop();
        if (!stack.empty()) {
            std::cout << "*";
        }
        else {
            std::cout << ";";
            break;
        }
    }
    std::cout << "\nразложение на простые множители числа по убыванию\n" << example << ":";
    //print(stack, "* ");
    while (true) {
        std::cout << help.top_inf();
        help.pop();
        if (!help.empty()) {
            std::cout << "*";
        }
        else {
            std::cout << ";";
            break;
        }
    }
    return 0;
}



//5,1
