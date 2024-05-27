#ifndef MyVector_h
#define MyVector_h
 
#include <iostream>

template<typename T>
class MyVector {
private:
	template<typename T>
	class node
	{
	public:
		node* pNext;
		T data;

		node(T data = T(), node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	int max_size;
	node<T> *pdata;
public:
	MyVector() : size(0), max_size(8), pdata(nullptr) {}
	MyVector(MyVector* ptr);
	~MyVector() {
		delete[] pdata;
	}

	void add_element(T data) {
		if (this->size + 1 == this->max_size) {
			this->resize(1);
		}
		node<T>* current = this->pdata;

		while (current->pNext->data != NULL) {
			current = current->pNext;
		}
		current->pNext = new node<T>(data);
		size++;
		this->sort();
	}
	int GetSize() { return size; }

	T& operator[](const int index) {
		int counter = 0;
		node<T>* current = this->pdata;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}

	MyVector& operator=(const MyVector& other) {
		if (this != &other) {
			delete[] pdata;
			max_size = other.max_size;
			size = other.size;
			pdata = new node<T>[other.max_size]; 
			for (int i = 0; i < size; ++i) {
				pdata[i] = other.pdata[i];
			}
		}
		return *this;
	}

	void delete_element(int n) {
		if (n < this->GetSize()) {
			MyVector<T> current = this->pdata;
			MyVector<T> previous = nullptr;
			for (int i = 0; i < n - 1; i++)
			{
				previous = current;
				current = current->pdata;
			}
			previous->pdata = current->pdata;
			current->~MyVector();
		}
	};
	void sort() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if ()
			}
		}
	};
	void resize(bool n) {
		if (n) {
			this->max_size *= 2;
		}
		else {
			this->max_size /= 2;
		}
		MyVector* ptr = new MyVector(this->pdata);
		this->pdata = ptr;
		ptr->~MyVector();
	};
	T GetData() {
		return this->pdata->data;
	};
};


#endif