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
	~MyVector();

	void add_element(T data);
	int GetSize() { return size; }

	T& operator[](const int index);
	MyVector& operator=(const MyVector& other);	

	void delete_element(int n);
	void sort();
	void resize(bool n);
	T GetData();
};


#endif