#include <iostream>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <map>
#include <fstream>

using namespace std;

void task1();
void task2();
int task3();
int task4();
void task5();
int task6();
int task7();
int task8();
int task9();
int menu();

int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        system("cls");
        switch (menu())
        {
        case 1:
            system("cls");
            task1();
            system("pause");
            break;
        case 2:
            system("cls");
            task2();
            system("pause");
            break;
        case 3:
            system("cls");
            task3();
            system("pause");
            break;
        case 4:
            system("cls");
            task4();
            system("pause");
            break;
        case 5:
            system("cls");
            task5();
            system("pause");
            break;
        case 6:
            system("cls");
            task6();
            system("pause");
            break;
        case 7:
            system("cls");
            task7();
            system("pause");
            break;
        case 8:
            system("cls");
            task8();
            system("pause");
            break;
        case 9:
            system("cls");
            task9();
            system("pause");
            break;
        default:
            cout << "нет такого варианта:\n";
            break;
        }
    }

    return 0;
}

int menu() {
    int choice;
    system("cls");
    cout << "выберите номер задания от 1 до 9" << endl;
    cin >> choice;
    return choice;
}

void task1() {
    std::string text;

    std::cout << "Введите текст:\n ";
    std::cin >> text;

    std::cout << "Позиции символа ';':\n ";
    for (size_t i = 0; i < text.length(); ++i) {
        if (text[i] == ';') {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

void task2() {
    std::string input, output;

    std::cout << "Введите последовательность символов:\n ";
    std::cin >> input;

    for (size_t i = 0; i < input.length(); i += 2) {
        output += input[i];
    }

    std::cout << "Последовательность с символами на четных позициях: \n" << output << std::endl;
}

//тут мне надоело постоянно писать std::


int task3() {
    string inputFilename, outputFilename, oldSymbol, newSymbol;

    cout << "Введите имя входного файла: \n";
    cin >> inputFilename;

    cout << "Введите имя выходного файла: \n";
    cin >> outputFilename;

    cout << "Введите символ для замены: \n";
    cin >> oldSymbol;

    cout << "Введите новый символ:\n ";
    cin >> newSymbol;

    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла:\n " << inputFilename << endl;
        return 1;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла: \n" << outputFilename << endl;
        inputFile.close();
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        for (size_t i = 0; i < line.length(); ++i) {
            if (line.at(i) == oldSymbol.at(0)) {
                line.at(i) = newSymbol.at(0);
            }
        }
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Замена символов выполнена успешно.\n" << endl;
    return 0;
}

void printVector(const vector<float>& vec) {
    cout << "Вектор: \n";
    for (float num : vec) {
        cout << fixed << setprecision(2) << num << " ";
    }
    cout << endl;
}

int task4() {
    vector<float> numbers(25);
    for (int i = 0; i < 25; ++i) {
        numbers[i] = i + 1;
    }

    cout << "Вектор до возведения в квадрат:\n" << endl;
    printVector(numbers);

    for (float& num : numbers) {
        num *= num;
    }

    cout << "Вектор после возведения в квадрат:\n" << endl;
    printVector(numbers);

    // Удаляем элемент с индексом 5
    numbers.erase(numbers.begin() + 5);

    cout << "Вектор после удаления элемента с индексом 5:\n" << endl;
    printVector(numbers);

    return 0;
}



class Card {
    string title;   
    string author;  
    int number;     
public:
    Card() : title(""), author(""), number(0) {}
    Card(string t, string a, int n) : title(t), author(a), number(0) {}
};

void task5() {
    vector<Card> cards;
    for (int i = 0; i < 5; i++) {
        string title;
        string author;
        int number;
        cout << "введите заглавие" << endl;
        cin >> title;
        cout << "введите авторa" << endl;
        cin >> author;
        cout << "введите количество имеющихся экземпляров" << endl;
        cin >> number;
        Card p(title, author, number);
        cards.push_back(p);
    }
}



void checkNumber(const list<int>& numbers, int x) {
    if (find(numbers.begin(), numbers.end(), x) != numbers.end()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int task6() {
    list<int> numbers = { 1, 3, 5, 7, 9 };
    int x;

    cout << "Введите число: \n";
    cin >> x;

    checkNumber(numbers, x);

    return 0;
}

class complex {
private:
    double whole;
    double imaginary;
public:
    complex() {
        whole = 0;
        imaginary = 0;
    };
    complex(const complex& num) : whole(num.whole), imaginary(num.imaginary) {}

    complex(double whole, double imaginary) : whole(whole), imaginary(imaginary) {}

    friend ostream& operator<<(ostream& out, const complex& c) {
        out << c.whole;
        if (c.imaginary >= 0) {
            out << " + i * " << c.imaginary;
        }
        else {
            out << " - i * " << -c.imaginary;
        }
        return out;
    }
    complex operator+(const complex& other) const {
        return complex(whole + other.whole, imaginary + other.imaginary);
    }
    
};

int task7() {
    list<complex> complexNumbers = {
        complex(-1.2, 6.3),
        complex(4.0, 0.7),
        complex(7.2, -0.8),
        complex(5.3, 3.0),
        complex(-4.9, 6.6),
        complex(-9.3, 0.2)
    };

    cout << "Список комплексных чисел:" << endl;
    for (const complex& c : complexNumbers) {
        cout << c << endl;
    }

    complex sum = complex(0, 0);
    for (const complex& c : complexNumbers) {
        sum = sum + c;
    }

    cout << "Сумма комплексных чисел: " << sum << endl;
    return 0;
}

int task8() {
    map<int, int> myMap;

    for (int i = 1; i <= 20; ++i) {
        myMap[i] = i * 10;
    }

    cout << "Отображение:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << " - " << it->second << endl;
    }

    for (auto it = myMap.begin(); it != myMap.end(); ) {
        if (it->first % 2 != 0) {
            it = myMap.erase(it);
        }
        else {
            ++it;
        }
    }

    cout << "Отображение после удаления пар с нечетными ключами:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << " - " << it->second << endl;
    }

    return 0;
}


int task9() {

    map<string, int> salaries;
    salaries["Ivanov"] = 45500;
    salaries["Petrov"] = 37000;
    salaries["Sidorov"] = 245000;
    salaries["Petrenko"] = 65000;
    salaries["Tovalds"] = 91200;
    salaries["Popov"] = 54600;
    salaries["Andrienko"] = 35000;


    map<string, string> departments;
    departments["Ivanov"] = "Research";
    departments["Petrov"] = "Research";
    departments["Sidorov"] = "Management";
    departments["Petrenko"] = "Management";
    departments["Tovalds"] = "Development";
    departments["Popov"] = "Research";
    departments["Andrienko"] = "Sales";


    map<string, int> departmentSalaries;


    int overallSalary = 0;
    for (auto it = salaries.begin(); it != salaries.end(); ++it) {
        string employee = it->first;
        int salary = it->second;
        overallSalary += salary;

        string department = departments[employee];
        departmentSalaries[department] += salary;
    }

    cout << "Research " << departmentSalaries["Research"] << endl;
    cout << "Management " << departmentSalaries["Management"] << endl;
    cout << "Development " << departmentSalaries["Development"] << endl;
    cout << "Sales " << departmentSalaries["Sales"] << endl;
    cout << "Overall " << overallSalary << endl;

    return 0;
}

