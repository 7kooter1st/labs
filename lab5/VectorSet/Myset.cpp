#include "Myset.h"

template<typename T>
int MySet<T>::q_find(T value) {
	for (int i = 0; i < this->GetSize(); i++) {
		if (value == this->GetData()) { return this->GetSize(); }
	}
	return NULL;
}

template<typename T>
bool MySet<T>::is_element(T value) {
	for (int i = 0; i < this->GetSize(); i++) {
		if (value == this->data) { return 1; }
	}
	return 0;
}

template<typename T>
void MySet<T>::operator+=(Myset& s) {
	for (int i = 0; i < s->GetSize(); i++) {
		this->add_element(s[i]);
	}
	int i = 0;
	int j = 0;
	while (i < this->GetSize()) {
		if (this[i] == ans[j + 1]) {
			this[i].delete_element(i);
			j--;
		}
		j++;
		i++;
	}
};

template<typename T>
void MySet<T>::operator-=(Myset& s) {
	for (int i = 0; i < s->GetSize(); i++) {
		for (int j = 0; j < this->GetSize(); j++) {
			if (this[j] == s[i]) {
				this->delete_element[j];
				break;
			}
		}
	}
};

template<typename T>
void MySet<T>::operator*=(Myset& s) {
	MySet<T>* ans;
	for (int i = 0; i < this.GetSize(); i++) {
		for (int j = 0; j < s.GetSize; j++) {
			if (this[i] == s[j]) {
				ans->add_element(s[i]);
				break;
			}
		}
	}
	this = ans;
};

template<typename T>
MySet<T> operator+(MySet<T>& s1, MySet<T>& s2) {
	MySet<T>* ans;
	for (int i = 0; i < s1.GetSize(); i++) {
		ans.add_element(s1[i]);
	}
	for (int i = 0; i < s2.GetSize(); i++) {
		ans.add_element(s2[i]);
	}
	int i = 0;
	int j = 0;
	while (i < ans.GetSize()) {
		if (ans[j] == ans[j + 1]) {
			ans.delete_element(i);
			j--;
		}
		j++;
		i++;
	}
	return ans;
};

template<typename T>
MySet<T> operator-(MySet<T>&, MySet<T>&) {
	MySet<T>* ans;
	for (int i = 0; i < s1.GetSize(); i++) {
		ans.add_element(s1[i]);
	}
	for (int i = 0; i < s2.GetSize(); i++) {
		int j = 0;
		int s = 0;
		while (j < ans.GetSize())
		{
			if (s2[i] == ans[s]) {
				ans.delete_element(s);
				s--;
			}
			else if (s2[i] < ans[s]) {
				break;
				}
			s++;
			j++;
		}
	}
	return ans;
};

template<typename T>
MySet<T> operator*(MySet<T>& s1, MySet<T>& s2) {
	MySet<T>* ans;
	for (int i = 0; i < s1.GetSize(); i++) {
		for (int j = 0; j < s2.GetSize; j++) {
			if (s1[i] == s2[j]) {
				ans->add_element(s1[i]);
				break;
			}
		}
	}
	return MySet;
};