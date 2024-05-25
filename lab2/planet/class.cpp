#include "class.h"
#include <iostream>
#include <fstream>
#include <vector>


planet::planet() {
        name_ = "";
        diameter_ = 0;
        life_ = 0;
        satelite_ = 0;
    }
planet::planet(char* name, unsigned int diameter, bool life, unsigned int satelite) {
        name_ = new char[strlen(name) + 1];
        strcpy(name_, name);
        diameter_ = diameter;
        life_ = life;
        satelite_ = satelite;
    }

planet::~planet() {
        if (name_ != nullptr) {
            delete[]name_;
        }
        if (diameter_ != 0) {
            diameter_ = 0;
        }
        if (life_ != 0) {
            life_ = 0;
        }
        if (satelite_ != 0) {
            satelite_ = 0;
        }
    }
    void planet::SetName(char* name) {
        this->name_ = new char[strlen(name) + 1];
        strcpy(this->name_, name);
    }
    void planet::SetDiameter(unsigned diameter) {
        this->diameter_ = diameter;
    }
    void planet::SetLife(bool life) {
        life_ = life;
    }
    void planet::SetSatelite(unsigned int satelite) {
        satelite_ = satelite;
    }
    char* planet::GetName() {
        return name_;
    }
    unsigned int planet::GetDiameter() {
        return diameter_;
    }
    bool planet::GetLife() {
        return life_;
    }
    unsigned int planet::GetSatelite() {
        return satelite_;
    }
    std::ofstream& operator<<(std::ofstream& out, planet*& pl) {
        out << pl->GetName() << ' ' << pl->GetDiameter() << ' ' << pl->GetLife() << ' ' << pl->GetSatelite() << '\n';
        return out;
    }

    bool operator<(planet& pl1, planet &pl2){
        if (strcmp(pl1.GetName(), pl2.GetName()) >= 0) {
            return 0;
        }
        else {
            return 1;
        }
    }

    bool operator==(planet& pl1, planet& pl2) {
        return strcmp(pl1.GetName(), pl2.GetName());
    }

    std::ifstream& operator>>(std::ifstream& in, planet*&pl) {
        char buf_name[MAX_NAME];
        unsigned int diameter;
        bool life;
        unsigned int satelite;
        in >> buf_name >> diameter >> life >> satelite;
        pl->SetDiameter(diameter);
        pl->SetLife(life);
        pl->SetSatelite(satelite);
        pl->SetName(buf_name);
        return in;
    }

    planet* read_db(char* name, planet**& planets, unsigned int& n) {
        std::ifstream rf(name, std::ios::out | std::ios::binary);
        if (!rf.is_open()) {
            std::cout << "Can't open file" << std::endl;
            return nullptr;
        }
        /*char buf_name[MAX_NAME];
        unsigned int diameter;
        bool life;
        unsigned int satelite;*/
        unsigned m = 1;
        for (unsigned int n = 0; !rf.eof(); n++, m++) {
            //rf >> buf_name >> diameter >> life >> satelite;
            resize(planets, n, m);
            rf >> planets[n];
            /*planets[n]->SetDiameter(diameter);
            planets[n]->SetLife(life);
            planets[n]->SetSatelite(satelite);
            planets[n]->SetName(buf_name);*/
        }
        n = m - 1;
        rf.close();
        if (!rf.good()) {
            std::cout << "Can't close file" << std::endl;
            return nullptr;
        }
    }

    planet* write_db(char* name, planet**& planets, unsigned int& n) {
        std::ofstream rf(name, std::ios::out | std::ios::binary);
        if (!rf.is_open()) {
            std::cout << "Can't open file" << std::endl;
            return nullptr;
        }
        for (int i = 0; i < n - 1; i++) {
            rf << planets[i];
        }
        rf.close();
        if (!rf.good()) {
            std::cout << "Can't close file" << std::endl;
            return nullptr;
        }
    }

    int menu() {
        system("cls");
        unsigned int m = 0;
        std::cout << "выберите действие: \n1)прочитать БД из файла \n2)найти планету\n3)добавить элемент\n4)удалить элемент\n";
        std::cout << "5)записать БД в файл\n6)вывести БД на экран\n7)отсортировать БД \n8)выход\n";
        std::cin >> m;
        return m;
    }

    void print_db(planet**& planets, unsigned int& n) {
        system("cls");
        char* stop = "";
        for (int i = 0; i < n; i++) {
            std::cout << planets[i]->GetName() << ' ' << planets[i]->GetDiameter() << ' ' << planets[i]->GetLife() << ' ' << planets[i]->GetSatelite() << std::endl;
        }
        system("pause");
    }

    void sort_db(planet**& planets, unsigned int& size) {
        unsigned int i = 0;
        unsigned int j = size - 1;
        char mid[MAX_NAME];
        strcpy(mid, planets[size / 2]->GetName());
        do {
            while (strcmp(planets[i]->GetName(), mid) < 0) {
                i++;
            }
            while (strcmp(planets[j]->GetName(), mid) > 0) {
                j--;
                std::cout << j << std::endl;
            }
            if (i <= j) {
                planet* tmp = planets[i];
                planets[i] = planets[j];
                planets[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);
        if (j > 0) {
            unsigned int l = j + 1;
            if (l > 1) {
                sort_db(planets, l);
            }
        }
        if (i < size) {
            planet** p = &planets[i];
            unsigned int o = size - i;
            if (o > 1) {
                sort_db(p, o);
            }
        }
    }

    unsigned int find(planet**& planets, unsigned int& n) {
        system("cls");
        char buf[MAX_NAME];
        std::cout << "введите название планеты" << std::endl;
        std::cin >> buf;

        for (int i = 0; i < n - 1; i++) {
            if (strcmp(planets[i]->GetName(), buf) == 0) {
                return i + 1;
            }
        }
        return 0;
    }

    void resize(planet**& arr, unsigned int& n, unsigned int& m) {
        planet** p = new planet * [m];
        unsigned int s;

        if (n > m) {
            s = m;
        }
        else {
            s = n;
        }

        for (int j = 0; j < s + 1; j++) {
            planet* tmp = new planet;
            p[j] = tmp;
        }
        for (int i = 0; i < s; i++) {
            p[i]->SetDiameter(arr[i]->GetDiameter());
            p[i]->SetLife(arr[i]->GetLife());
            p[i]->SetSatelite(arr[i]->GetSatelite());
            p[i]->SetName(arr[i]->GetName());
            delete arr[i];
        }

        if (arr != nullptr) {
            delete[]arr;
        }
        arr = p;
    }

    void add(planet**& planets, unsigned int& n) {
        system("cls");
        char name[MAX_NAME] = "";
        unsigned int diameter;
        bool life;
        unsigned int satelite;
        unsigned int m = n + 1;
        resize(planets, n, m);
        n++;
        std::cout << "введите название планеты" << std::endl;
        std::cin >> name;
        planets[n - 1]->SetName(name);
        std::cout << "введите диаметр планеты" << std::endl;
        std::cin >> diameter;
        planets[n - 1]->SetDiameter(diameter);
        std::cout << "введите наличие жизни планеты" << std::endl;
        std::cin >> life;
        planets[n - 1]->SetLife(life);
        std::cout << "введите кол-во спутников планеты" << std::endl;
        std::cin >> satelite;
        planets[n - 1]->SetSatelite(satelite);
    }

    int del(planet**& planets, unsigned int& n) {
        system("cls");
        unsigned int i;
        unsigned int m = n - 1;
        std::cout << "введите номер удаляемого элемента" << std::endl;
        std::cin >> i;
        if (i<0 || i>n) {
            std::cout << "нет планеты с таким номером";
            system("pause");
            return 0;
        }
        planets[i - 1]->SetDiameter(planets[n - 1]->GetDiameter());
        planets[i - 1]->SetName(planets[n - 1]->GetName());
        planets[i - 1]->SetLife(planets[n - 1]->GetLife());
        planets[i - 1]->SetSatelite(planets[n - 1]->GetSatelite());
        resize(planets, n, m);
        n--;
        return 0;
    }
    int start_planet() {
        setlocale(LC_ALL, "russian");
        unsigned int size = 0;
        char* file_name = "planets.txt";
        planet** planets = new planet * [1];
        unsigned int ind;
        while (true) {
            switch (menu()) {
            case 1:
                read_db(file_name, planets, size);
                break;
            case 2:
                ind = find(planets, size);
                if (ind > 0) {
                    std::cout << "это планета под номером " << ind << std::endl;
                }
                else {
                    std::cout << "Такой планеты нет" << std::endl;
                }
                system("pause");
                break;
            case 3:
                add(planets, size);
                break;
            case 4:
                del(planets, size);
                break;
            case 5:
                write_db(file_name, planets, size);
                break;
            case 6:
                std::cout << size << std::endl;
                print_db(planets, size);
                break;
            case 7:
                sort_db(planets, size);
                break;
            case 8:
                return 0;
            default:
                std::cout << " Неправильный ввод" << std::endl;
                break;
            }
        }
        return 0;
    }