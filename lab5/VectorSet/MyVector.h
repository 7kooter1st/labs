#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

template<typename T>
class MyVector {
private:
    template<typename U>
    class Node {
    public:
        Node* pNext;
        U data;

        Node(U data = U(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int size;
    int max_size;
    Node<T>* pdata;

public:
    MyVector() : size(0), max_size(8), pdata(nullptr) {}

    MyVector(const MyVector& other) {
        size = other.size;
        max_size = other.max_size;
        if (other.pdata == nullptr) {
            pdata = nullptr;
        }
        else {
            pdata = new Node<T>(other.pdata->data);
            Node<T>* current = pdata;
            Node<T>* otherCurrent = other.pdata->pNext;
            while (otherCurrent != nullptr) {
                current->pNext = new Node<T>(otherCurrent->data);
                current = current->pNext;
                otherCurrent = otherCurrent->pNext;
            }
        }
    }

    ~MyVector() {
        while (pdata != nullptr) {
            Node<T>* temp = pdata;
            pdata = pdata->pNext;
            delete temp;
        }
    }

    void add_element(T data) {
        if (size == 0) {
            pdata = new Node<T>(data);
        }
        else {
            Node<T>* current = pdata;
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            current->pNext = new Node<T>(data);
        }
        size++;
    }

    int GetSize() const { return size; }

    const T& operator[](const int index) const {
        int counter = 0;
        Node<T>* current = pdata;
        while (current != nullptr) {
            if (counter == index) return current->data;
            current = current->pNext;
            counter++;
        }
        throw std::out_of_range("Index out of range");
    }

    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this;
        this->~MyVector();
        size = other.size;
        max_size = other.max_size;
        if (other.pdata == nullptr) {
            pdata = nullptr;
        }
        else {
            pdata = new Node<T>(other.pdata->data);
            Node<T>* current = pdata;
            Node<T>* otherCurrent = other.pdata->pNext;
            while (otherCurrent != nullptr) {
                current->pNext = new Node<T>(otherCurrent->data);
                current = current->pNext;
                otherCurrent = otherCurrent->pNext;
            }
        }
        return *this;
    }

    void delete_element(int n) {
        if (n < 0 || n >= size) return;
        if (n == 0) {
            Node<T>* temp = pdata;
            pdata = pdata->pNext;
            delete temp;
        }
        else {
            Node<T>* current = pdata;
            for (int i = 0; i < n - 1; ++i) {
                current = current->pNext;
            }
            Node<T>* temp = current->pNext;
            current->pNext = temp->pNext;
            delete temp;
        }
        size--;
    }
};

#endif