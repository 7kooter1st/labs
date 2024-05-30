#include <iostream>
#include "worker/Vector.h"
#include "worker/abstract_class.h"
#include "worker/hr.h"
#include "worker/enginer.h"
#include "worker/administration.h"
#include "worker/functions.cpp"

int main() {
    setlocale(LC_ALL, "Russian");
    MyVector<Worker*> container;

    container.add_element(new HR("Иван Иванов", 35, 10, 50));
    container.add_element(new Engineer("Пётр петров", 40, 15, "Programming"));
    container.add_element(new Administration("Мария Сидорова", 28, 5, "HR department"));

    std::cout << "демонстрация" << std::endl;
    print(container);
    std::cout << std::endl;

    remove(container, 2);
    std::cout << "удаление элемента с индеком 1" << std::endl;
    print(container);
    std::cout << std::endl;

    clear(container);
    std::cout << "очищение контейнера" << std::endl;
    print(container);
    std::cout << std::endl;

    char choice;
    do {
        std::cout << "меню" << std::endl;
        std::cout << "1. Добавить элемент" << std::endl;
        std::cout << "2. Вывести элементы" << std::endl;
        std::cout << "3. Удалить элемент" << std::endl;
        std::cout << "4. Очистить Контейнер" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие:\n";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            char name[100], specialization[100], department[100];
            int age, experience, num_employees;

            std::cout << "введите имя\n";
            std::cin.ignore();
            std::cin.getline(name, 100);
            std::cout << "Введите возраст\n";
            std::cin >> age;
            std::cout << "Введите опыт\n";
            std::cin >> experience;

            char type;
            std::cout << "Выберите тип сотрудника (К – HR, I – Инженер, A – Администрация):\n";
            std::cin >> type;

            switch (type) {
            case 'K': {
                std::cout << "Введите количество сотрудников:\n";
                std::cin >> num_employees;
                container.add_element(new HR(name, age, experience, num_employees));
                break;
            }
            case 'I': {
                std::cout << "Введите специализацию:\n";
                std::cin.ignore();
                std::cin.getline(specialization, 100);
                container.add_element(new Engineer(name, age, experience, specialization));
                break;
            }
            case 'A': {
                std::cout << "Введите отдел:\n";
                std::cin.ignore();
                std::cin.getline(department, 100);
                container.add_element(new Administration(name, age, experience, department));
                break;
            }
            default:
                std::cout << "Неправильный тип сотрудника!" << std::endl;
            }
            break;
        }
        case '2': {
            print(container);
            break;
        }
        case '3': {
            int index;
            std::cout << "Введите индекс элемента, который нужно удалить:\n";
            std::cin >> index;
            remove(container, index);
            break;
        }
        case '4': {
            clear(container);
            break;
        }
        case '0':
            std::cout << "Выход из программы."<< std::endl;
            break;
        default:
            std::cout << "Неправильный выбор!" << std::endl;
        }
    } while (choice != '0');

    return 0;
}