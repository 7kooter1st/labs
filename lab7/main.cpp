#include <iostream>
#include "worker/Vector.h"
#include "worker/abstract_class.h"
#include "worker/hr.h"
#include "worker/enginer.h"
#include "worker/administration.h"

int main() {
    MyVector<Worker*> container;

    // Demonstration mode
    container.add_element(new HR("Иван Иванов", 35, 10, 50));
    container.add_element(new Engineer("Пётр петров", 40, 15, "Programming"));
    container.add_element(new Administration("Мария Сидорова", 28, 5, "HR department"));

    std::cout << "демонстрация" << std::endl;
    print(container);
    std::cout << std::endl;

    remove(container, 1);
    std::cout << "удаление элемента с индеком 1" << std::endl;
    print(container);
    std::cout << std::endl;

    clear(container);
    std::cout << "очищение контейнера" << std::endl;
    print(container);
    std::cout << std::endl;

    // Interactive mode
    char choice;
    do {
        std::cout << "меню" << std::endl;
        std::cout << "1. Добавить элемент" << std::endl;
        std::cout << "2. Print elements" << std::endl;
        std::cout << "3. Remove element" << std::endl;
        std::cout << "4. Clear container" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            char name[100], specialization[100], department[100];
            int age, experience, num_employees;

            std::cout << "Enter name: ";
            std::cin.ignore();
            std::cin.getline(name, 100);
            std::cout << "Enter age: ";
            std::cin >> age;
            std::cout << "Enter experience: ";
            std::cin >> experience;

            char type;
            std::cout << "Choose employee type (K - HR, I - Engineer, A - Administration): ";
            std::cin >> type;

            switch (type) {
            case 'K': {
                std::cout << "Enter number of employees: ";
                std::cin >> num_employees;
                container.add_element(new HR(name, age, experience, num_employees));
                break;
            }
            case 'I': {
                std::cout << "Enter specialization: ";
                std::cin.ignore();
                std::cin.getline(specialization, 100);
                container.add_element(new Engineer(name, age, experience, specialization));
                break;
            }
            case 'A': {
                std::cout << "Enter department: ";
                std::cin.ignore();
                std::cin.getline(department, 100);
                container.add_element(new Administration(name, age, experience, department));
                break;
            }
            default:
                std::cout << "Incorrect employee type!" << std::endl;
            }
            break;
        }
        case '2': {
            print(container);
            break;
        }
        case '3': {
            int index;
            std::cout << "Enter index of element to remove: ";
            std::cin >> index;
            remove(container, index);
            break;
        }
        case '4': {
            clear(container);
            break;
        }
        case '0':
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Incorrect choice!" << std::endl;
        }
    } while (choice != '0');

    return 0;
}