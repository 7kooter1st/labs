#ifndef MyStack_h           
#define MyStack_h           

#include <iostream>
#include "MyVector.h"

template<typename T>
class MySet : public MyVector<T>{
private:

public:
	MySet();
	~MySet();
	bool is_element(T value);
	int q_find(T value);
	void operator+=(Myset&);
	void operator-=(Myset&);
	void operator*=(Myset&);
};

template<typename T>
MySet<T> operator+(MySet<T>&, MySet<T>&);

template<typename T>
MySet<T> operator-(MySet<T>&, MySet<T>&);

template<typename T>
MySet<T> operator*(MySet<T>&, MySet<T>&);



#endif 