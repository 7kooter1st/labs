#ifndef MyStack_h           
#define MyStack_h           

#include <iostream>
#include "MyVector.h"

template<typename T>
class MySet : public MyVector<T> {
private:

public:
    MySet() {}
    bool is_element(T value);
    int q_find(T value);

    MySet& operator+=(MySet& s) {
        for (int i = 0; i < s.GetSize(); i++) {
            this->add_element(s[i]);
        }
        int i = 0;
        while (i < this->GetSize()) {
            for (int j = i + 1; j < this->GetSize(); j++) {
                if (this->operator[](i) == this->operator[](j)) {
                    this->delete_element(j);
                    j--; 
                }
            }
            i++;
        }
        return *this;
    }

    MySet& operator-=(const MySet& s) {
        for (int i = 0; i < s.GetSize(); i++) {
            for (int j = 0; j < this->GetSize(); j++) {
                if (this->operator[](j) == s[i]) {
                    this->delete_element(j);
                    j--; 
                    break;
                }
            }
        }
        return *this;
    }

    MySet& operator*=(const MySet& s) {
        MySet<T> ans;
        for (int i = 0; i < this->GetSize(); i++) {
            for (int j = 0; j < s.GetSize(); j++) {
                if (this->operator[](i) == s[j]) {
                    ans.add_element(this->operator[](i));
                    break;
                }
            }
        }
        *this = ans;
        return *this;
    }
};

template<typename T>
MySet<T> operator+(MySet<T>& a, MySet<T>& b);

template<typename T>
MySet<T> operator-(MySet<T>& a, MySet<T>& b);

template<typename T>
MySet<T> operator*(MySet<T>& a, MySet<T>& b);

#endif