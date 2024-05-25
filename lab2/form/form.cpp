#include "form.h"
#include <iostream>
#include <fstream>
#include <vector>


form::form() {
	name_ = nullptr;
	PostIndex_ = 0;
	answer_ = 0;
	rating_ = 0.0;
}
form::form(char* name, unsigned int PostIndex, bool answer, double rating) {
	strcpy(name_,name);
	PostIndex_ = PostIndex;
	answer_ = answer;
	rating_ = rating;
}
form::~form() {
    delete[]name_;
    name_ = nullptr;
}

void form::SetName(char* name) {
    delete[] this->name_;
    this->name_ = new char[strlen(name) + 1];
    strcpy(this->name_, name);
}
void form::SetPostIndex(unsigned int PostIndex){
	PostIndex_ = PostIndex;
}
void form::SetAnswer(bool answer) {
	answer_ = answer;
}
void form::SetRating(double rating) {
	rating_ = rating;
}

char* form::GetName() {
	return name_;
}
unsigned int form::GetPostIndex() {
	return PostIndex_;
}
bool form::GetAnswer() {
	return answer_;
}
double form::GetRating() {
	return rating_;
}

std::ifstream& operator>>(std::ifstream& in, form*& pl) {
    char buf_name[MAX_NAME];
    unsigned int PostIndex;
    bool Answer;
    double Rating;
    in >> buf_name >> PostIndex >> Answer >> Rating;
    pl->SetName(buf_name);
    pl->SetPostIndex(PostIndex);
    pl->SetAnswer(Answer);
    pl->SetRating(Rating);
    return in;
}

form* read_db(char* name, form**& forms, unsigned int& n) {
    std::ifstream rf(name, std::ios::out | std::ios::binary);
    if (!rf.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return nullptr;
    }
    unsigned m = 1;
    for (unsigned int n = 0; !rf.eof(); n++, m++) {
        resize(forms, n, m);
        rf >> forms[n];
    }
    n = m - 1;
    rf.close();
    if (!rf.good()) {
        std::cout << "Can't close file" << std::endl;
        return nullptr;
    }
}

form* write_db(char* name, form**& planets, unsigned int& n) {
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

int Menu() {
    system("cls");
    unsigned int m = 0;
    std::cout << "выберите действие: \n1)прочитать БД из файла \n2)найти анкету\n3)добавить элемент\n4)удалить элемент\n";
    std::cout << "5)записать БД в файл\n6)вывести БД на экран\n7)отсортировать БД \n8)выход\n";
    std::cin >> m;
    return m;
}

void print_db(form**& forms, unsigned int& n) {
    system("cls");
    char* stop = "";
    for (int i = 0; i < n; i++) {
        std::cout << forms[i]->GetName() << ' ' << forms[i]->GetPostIndex() << ' ' << forms[i]->GetAnswer() << ' ' << forms[i]->GetRating() << std::endl;
    }
    system("pause");
}

void sort_db(form**& forms, unsigned int& size) {
    unsigned int i = 0;
    unsigned int j = size - 1;
    char mid[MAX_NAME];
    strcpy(mid, forms[size / 2]->GetName());
    do {
        while (strcmp(forms[i]->GetName(), mid) < 0) {
            i++;
        }
        while (strcmp(forms[j]->GetName(), mid) > 0) {
            j--;
            std::cout << j << std::endl;
        }
        if (i <= j) {
            form* tmp = forms[i];
            forms[i] = forms[j];
            forms[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        unsigned int l = j + 1;
        if (l > 1) {
            sort_db(forms, l);
        }
    }
    if (i < size) {
        form* *p = &forms[i];
        unsigned int o = size - i;
        if (o > 1) {
            sort_db(p, o);
        }
    }
}

unsigned int find(form**& forms, unsigned int& n) {
    system("cls");
    char buf[MAX_NAME];
    std::cout << "введите название планеты" << std::endl;
    std::cin >> buf;

    for (int i = 0; i < n - 1; i++) {
        if (strcmp(forms[i]->GetName(), buf) == 0) {
            return i + 1;
        }
    }
    return 0;
}

void resize(form**& arr, unsigned int& n, unsigned int& m) {
    form** p = new form * [m];
    unsigned int s;

    if (n > m) {
        s = m;
    }
    else {
        s = n;
    }

    for (int j = 0; j < s + 1; j++) {
        form* tmp = new form;
        p[j] = tmp;
    }
    for (int i = 0; i < s; i++) {
        p[i]->SetName(arr[i]->GetName());
        p[i]->SetPostIndex(arr[i]->GetPostIndex());
        p[i]->SetAnswer(arr[i]->GetAnswer());
        p[i]->SetRating(arr[i]->GetRating());
        delete arr[i];
    }

    if (arr != nullptr) {
        delete[]arr;
    }
    arr = p;
}

void add(form**& forms, unsigned int& n) {
    system("cls");
    char name[MAX_NAME] = "";
    unsigned int PostIndex;
    bool answer;
    double rating;
    unsigned int m = n + 1;
    resize(forms, n, m);
    n++;
    std::cout << "введите тему опроса" << std::endl;
    std::cin >> name;
    forms[n - 1]->SetName(name);
    std::cout << "введите почтовый индекс" << std::endl;
    std::cin >> PostIndex;
    forms[n - 1]->SetPostIndex(PostIndex);
    std::cout << "опрос анонимный?" << std::endl;
    std::cin >> answer;
    forms[n - 1]->SetAnswer(answer);
    std::cout << "введите оценку опроса" << std::endl;
    std::cin >> rating;
    forms[n - 1]->SetRating(rating);
}

int del(form**& forms, unsigned int& n) {
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
    forms[i - 1]->SetPostIndex(forms[n - 1]->GetPostIndex());
    forms[i - 1]->SetName(forms[n - 1]->GetName());
    forms[i - 1]->SetAnswer(forms[n - 1]->GetAnswer());
    forms[i - 1]->SetRating(forms[n - 1]->GetRating());
    resize(forms, n, m);
    n--;
    return 0;
}

int start_form() {
    setlocale(LC_ALL, "russian");
    unsigned int size = 0;
    char* file_name = "form.txt";
    form** forms = new form * [1];
    unsigned int ind;
    while (true) {
        switch (Menu()) {
        case 1:
            read_db(file_name, forms, size);
            break;
        case 2:
            ind = find(forms, size);
            if (ind > 0) {
                std::cout << "это опрос под номером " << ind << std::endl;
            }
            else {
                std::cout << "Такого опроса нет" << std::endl;
            }
            system("pause");
            break;
        case 3:
            add(forms, size);
            break;
        case 4:
            del(forms, size);
            break;
        case 5:
            write_db(file_name, forms, size);
            break;
        case 6:
            std::cout << size << std::endl;
            print_db(forms, size);
            break;
        case 7:
            sort_db(forms, size);
            break;
        case 8:
            return 0;
        default:
            std::cout << "Неправильный ввод\n" << std::endl;
            break;
        }
    }
    return 0;
}