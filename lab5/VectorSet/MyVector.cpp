//#include "MyVector.h"
//
//template<typename T>
//MyVector<T>::MyVector(MyVector* ptr = nullptr) {
//	for (int i = 0; i < max_size; i++) {
//		this->pdata->pNext = new node<T>(ptr->pdata->data);
//		size++;
//	}
//}
//
//template<typename T>
//MyVector<T>::~MyVector() {
//	delete[] pdata;
//}
//
//template<typename T>
//void MyVector<T>::add_element(T data) {
//	if (this->size+1 == this->max_size) {
//		this->resize(1);
//	}
//	node<T>* current = this->pdata;
//
//	while (current->pNext->data != NULL) {
//		current = current->pNext;
//	}
//	current->pNext = node<T>(data);
//	size++;
//	this->sort();
//}
//
//template<typename T>
//void MyVector<T>::delete_element(int n) {
//	if (n < this->GetSize()) {
//		MyVector<T> current = this->pdata;
//		MyVector<T> previous = nullptr;
//		for (int i = 0; i < n - 1; i++)
//		{
//			previous = current;
//			current = current->pdata;
//		}
//		previous->pdata = current->pdata;
//		current->~MyVector();
//	}
//}
//
//template<typename T>
//void MyVector<T>::sort() {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if()
//		}
//	}
//}
//
//template<typename T>
//void MyVector<T>::resize(bool n) {
//	if (n) {
//		this->max_size *= 2;
//		MyVector* ptr = new MyVector(this->pdata);
//	}
//	else {
//		this->max_size /= 2;
//		MyVector* ptr = new MyVector(this->pdata);
//	}
//	this->pdata = ptr;
//	ptr->~MyVector();
//}
//
//template<typename T>
//T MyVector<T>::GetData() {
//	return this->pdata->data;
//}
//
//
//template<typename T>
//T& MyVector<T>::operator[](const int index) {
//	int counter = 0;
//	node<T>* current = this->pdata;
//	while (current != nullptr) {
//		if (counter == index) {
//			return current->data;
//		}
//		current = current->pNext;
//		counter++;
//	}
//}

//template<typename T>
//MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
//	if (this != &other) {
//		delete[] pdata;
//		max_size = other.max_size;
//		size = other.size;
//		pdata = new [other.max_size];
//		for (int i = 0; i < size; ++i) {
//			pdata[i] = other.pdata[i];
//		}
//	}
//	return *this;
//}

//template<typename T>
//MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
//	if (this == &other) {
//		return *this;
//	}
//
//	while (head != nullptr) {
//		node<T>* temp = head;
//		head = head->pNext;
//		delete temp;
//	}
//
//	copy_from(other);
//
//	return *this;
//}



