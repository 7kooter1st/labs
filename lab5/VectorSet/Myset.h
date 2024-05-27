#ifndef MYSET_H
#define MYSET_H

#include "MyVector.h"

template<typename T>
class MySet : public MyVector<T> {
public:
    MySet() : MyVector<T>(){}
    ~MySet() {}

    bool is_element(T value) const {
        for (int i = 0; i < this->GetSize(); ++i) {
            if ((*this)[i] == value) return true;
        }
        return false;
    }

    MySet<T>& operator+=(const MySet<T>& s) {
        for (int i = 0; i < s.GetSize(); ++i) {
            if (!is_element(s[i])) {
                this->add_element(s[i]);
            }
        }
        return *this;
    }

    MySet<T>& operator-=(const MySet<T>& s) {
        for (int i = s.GetSize() - 1; i >= 0; --i) {
            for (int j = this->GetSize() - 1; j >= 0; --j) {
                if ((*this)[j] == s[i]) {
                    this->delete_element(j);
                    break;
                }
            }
        }
        return *this;
    }

    MySet<T>& operator*=(const MySet<T>& s) {
        MySet<T> result;
        for (int i = 0; i < this->GetSize(); ++i) {
            if (s.is_element((*this)[i])) {
                result.add_element((*this)[i]);
            }
        }
        *this = result;
        return *this;
    }
};

template<typename T>
MySet<T> operator+(MySet<T>& a, MySet<T>& b) {
    MySet<T> result = a;
    result += b;
    return result;
}

template<typename T>
MySet<T> operator-(MySet<T>& a, MySet<T>& b) {
    MySet<T> result = a;
    result -= b;
    return result;
}

template<typename T>
MySet<T> operator*(MySet<T>& a, MySet<T>& b) {
    MySet<T> result = a;
    result *= b;
    return result;
}

#endif