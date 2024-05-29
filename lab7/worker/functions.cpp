#include <iostream>
#include "Vector.h"
#include "abstract_class.h"

void print(const MyVector<Worker*>& container) {
    for (int i = 0; i < container.GetSize(); i++) {
        std::cout << "Index " << i << ": ";
        container[i]->show();
    }
}

void remove(MyVector<Worker*>& container, int index) {
    if (index < 0 || index >= container.GetSize()) {
        return;
    }

    delete container[index];
    container.delete_element(index);
}

void clear(MyVector<Worker*>& container) {
    container.clear();
}