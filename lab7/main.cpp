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

    container.add_element(new HR("���� ������", 35, 10, 50));
    container.add_element(new Engineer("ϸ�� ������", 40, 15, "Programming"));
    container.add_element(new Administration("����� ��������", 28, 5, "HR department"));

    std::cout << "������������" << std::endl;
    print(container);
    std::cout << std::endl;

    remove(container, 2);
    std::cout << "�������� �������� � ������� 1" << std::endl;
    print(container);
    std::cout << std::endl;

    clear(container);
    std::cout << "�������� ����������" << std::endl;
    print(container);
    std::cout << std::endl;

    char choice;
    do {
        std::cout << "����" << std::endl;
        std::cout << "1. �������� �������" << std::endl;
        std::cout << "2. ������� ��������" << std::endl;
        std::cout << "3. ������� �������" << std::endl;
        std::cout << "4. �������� ���������" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cout << "�������� ��������:\n";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            char name[100], specialization[100], department[100];
            int age, experience, num_employees;

            std::cout << "������� ���\n";
            std::cin.ignore();
            std::cin.getline(name, 100);
            std::cout << "������� �������\n";
            std::cin >> age;
            std::cout << "������� ����\n";
            std::cin >> experience;

            char type;
            std::cout << "�������� ��� ���������� (� � HR, I � �������, A � �������������):\n";
            std::cin >> type;

            switch (type) {
            case 'K': {
                std::cout << "������� ���������� �����������:\n";
                std::cin >> num_employees;
                container.add_element(new HR(name, age, experience, num_employees));
                break;
            }
            case 'I': {
                std::cout << "������� �������������:\n";
                std::cin.ignore();
                std::cin.getline(specialization, 100);
                container.add_element(new Engineer(name, age, experience, specialization));
                break;
            }
            case 'A': {
                std::cout << "������� �����:\n";
                std::cin.ignore();
                std::cin.getline(department, 100);
                container.add_element(new Administration(name, age, experience, department));
                break;
            }
            default:
                std::cout << "������������ ��� ����������!" << std::endl;
            }
            break;
        }
        case '2': {
            print(container);
            break;
        }
        case '3': {
            int index;
            std::cout << "������� ������ ��������, ������� ����� �������:\n";
            std::cin >> index;
            remove(container, index);
            break;
        }
        case '4': {
            clear(container);
            break;
        }
        case '0':
            std::cout << "����� �� ���������."<< std::endl;
            break;
        default:
            std::cout << "������������ �����!" << std::endl;
        }
    } while (choice != '0');

    return 0;
}