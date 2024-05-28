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
    Node<T>* head;

public:
    MyVector() : size(0), max_size(8), head(nullptr) {}

    MyVector(const MyVector& other) {
        size = other.size;
        max_size = other.max_size;
        if (other.head == nullptr) {
            head = nullptr;
        }
        else {
            head = new Node<T>(other.head->data);
            Node<T>* current = head;
            Node<T>* otherCurrent = other.head->pNext;
            while (otherCurrent != nullptr) {
                current->pNext = new Node<T>(otherCurrent->data);
                current = current->pNext;
                otherCurrent = otherCurrent->pNext;
            }
        }
    }

    ~MyVector() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->pNext;
            delete temp;
        }
    }

    void add_element(T data) {
        if (size == 0) {
            head = new Node<T>(data);
        }
        else {
            Node<T>* current = head;
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
        Node<T>* current = head;
        while (current != nullptr) {
            if (counter == index) return current->data;
            current = current->pNext;
            counter++;
        }
        throw std::out_of_range("Index out of range");
    }

    void delete_element(int n) {
        if (n < 0 || n >= size) return;
        if (n == 0) {
            Node<T>* temp = head;
            head = head->pNext;
            delete temp;
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < n - 1; ++i) {
                current = current->pNext;
            }
            Node<T>* temp = current->pNext;
            current->pNext = temp->pNext;
            delete temp;
        }
        size--;
    }
    const MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this; // Не делать ничего, если это один и тот же объект

        // Удалите старые узлы (если есть)
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->pNext;
            delete temp;
        }

        // Скопируйте данные из `other`
        size = other.size;
        max_size = other.max_size;
        if (other.head == nullptr) {
            head = nullptr;
        }
        else {
            head = new Node<T>(other.head->data);
            Node<T>* current = head;
            Node<T>* otherCurrent = other.head->pNext;
            while (otherCurrent != nullptr) {
                current->pNext = new Node<T>(otherCurrent->data);
                current = current->pNext;
                otherCurrent = otherCurrent->pNext;
            }
        }
        return *this; // Возвращаем ссылку на текущий объект
    }
};

#endif