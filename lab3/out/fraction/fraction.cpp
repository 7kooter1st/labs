#include "fraction.h"
#include <iostream>
#include <cstring>


fraction::fraction(char* name) {
	int i = 0;
	int arr[3] = {};
	bool flag = 0;
	if (name[0] == '-') {
		flag = 1;
	}
	char* suka = new char[strlen(name) + 1];
	strcpy(suka, name);
	char* ch = strtok(suka, " /");
	while (ch != NULL) {
		char n[MAX_NAME] = "";
		strcpy(n, ch);
		ch = strtok(NULL, " /");
		int s = 0;
		int j = 0;
		if (i == 0 && flag) {
			j = 1;
		}
		else {
			j = 0;
		}
		for (; j < strlen(n); j++) {
			s += (int(n[j]) - 48) * pow(10, strlen(n) - j - 1);
		}
		arr[i] = s;
		i++;
	}
	num_ = arr[0] * arr[2] + arr[1];
	den_ = arr[2];
	if (flag) { num_ *= -1; }
	//if (f) num_ *= 1;
	//else num_ *= -1;
	//if (t) num_ += 1;
	//else num_ *= -1;
}

fraction::fraction(double n) {
	int i = 0;
	for (; int(n) != n; i++) {
		n *= 10;
	}
	int m = n;
	int d = pow(10, i);
	int gcd = GCD(m, d);
	m /= gcd;
	d /= gcd;
	num_ = m;
	den_ = d;
}


fraction::~fraction() {}

//void fraction::SetFract(char* name) {
//	/*int j = 0;
//	char* fp = "";
//	char* sp = "";
//	char* tp = "";
//	char* mas[3] = {fp, sp, tp};
//	for (int i = 0; name[i] != '\0'; i++) {
//		strcat(mas[j], name[i]);
//		if (name[i] == ' ' || name[i] == '/') {
//			j++;
//		}
//	}*/
//	int i = 0;
//	int arr[3] = {};
//	bool flag = 0;
//	if (name[0] == '-') {
//		flag = 1;
//	}
//	char* suka = new char[strlen(name) + 1];
//	strcpy(suka, name);
//	char* ch = strtok(suka, " /");
//	while (ch != NULL) {
//		char n[MAX_NAME] = "";
//		strcpy(n, ch);
//		ch = strtok(NULL, " /");
//		int s = 0;
//		int j = 0;
//		if (i == 0 && flag) {
//			j = 1;
//		}
//		else {
//			j = 0;
//		}
//		for (;j < strlen(n); j++) {
//			s += (int(n[j]) - 48) * pow(10, strlen(n) - j - 1);
//		}
//		arr[i] = s;
//		i++;
//	}
//	num_ = arr[0] * arr[2] + arr[1];
//	den_ = arr[2];
//	if (flag) { num_ *= -1; }
//}

int GCD(int fp, int sp) {
	if (fp < sp) {
		int help = abs(fp);
		fp = abs(sp);
		sp = help;
	}
	int a = sp;
	if (a == 0) { return 1; }
	while (true) {
		if ((fp % a == 0) && (sp % a == 0)) {
			break;
		}
		a--;
	}
	return a;
}

int check(char name[]) {
	for (int i = 0; i < strlen(name); i++) {
		if (name[i] == ' ')
			return 0;
		else if (name[i] == '.')
			return 1;
		else if (name[i] == '/')
			return 2;
	}
	return 1;
}

std::istream& operator>>(std::istream& in, fraction& fr) {
	char name[MAX_NAME] = "";
	std::cin.getline(name, MAX_NAME);
	int ch = check(name);
	if (ch = 0) {
		fraction z(name);
	}
	else if (ch = 1) {
		double sum = 0;
		char* wp = strtok(name, ".");
		char w[MAX_NAME] = "";
		strcpy(w, wp);
		int i = 0;
		int minus = 1;
		if (w[0] == '-') { i++; minus-=2; }
		for (; i < strlen(w); i++) {
			sum += (int(w[i]) - 48) * pow(10, strlen(w) - i - 1);
		}
		wp = strtok(NULL, ".");
		if (wp != NULL) {
			strcpy(w, wp);
			for (int i = 0; i < strlen(w); i++) {
				double w1 = int(w[i]) - 48;
				sum += w1 / pow(10, i + 1);
				/*sum += (int(w[i]) - 48) / pow(10, i - strlen(w) - 1);*/
			}
		}
		fraction n(sum);
		fr = n;
		if (minus) { fr.SetNum(fr.GetNum() * (-1)); }
	}
	else if (ch == 3) {
		double sum = 0;
		char* wp = strtok(name, "/");
		char w[MAX_NAME];
		strcpy(w, wp);
		int i = 0;
		int minus = 1;
		if (w[0] == '-') { i++; minus-=2; }
		for (int i = 0; i < strlen(w); i++) {
			sum += (int(w[i]) - 48) * pow(10, strlen(w) - i - 1);
		}
		fr.SetNum(sum * minus);
		sum = 0;
		wp = strtok(NULL, "/");
		strcpy(w, wp);
		for (int i = 0; i < strlen(w); i++) {
			sum += (int(w[i]) - 48) * pow(10, strlen(w) - i - 1);
		}
		fr.SetDen(sum);
	}
	int gcd = GCD(fr.GetNum(), fr.GetDen());
	fr.SetNum(fr.GetNum() / gcd );
	fr.SetDen(fr.GetDen() / gcd);
	return in;
}



std::ostream& operator<<(std::ostream& out, fraction& fr) {
	int wp = fr.WholePart();
	if (wp < 0) fr.SetNum(fr.GetNum()*-1);
	int a = fr.GetNum();
	int b = fr.GetDen();
	fr.SetNum(a / GCD(a, b));
	fr.SetDen(b / GCD(a, b));
	int n = abs(fr.GetNum()) - abs(wp * fr.GetDen());
	int d = abs(fr.GetDen());
	out << wp << " " << n << "/" << d;
	return out;
}


int fraction::pow(int a, int b) {
	int n = 1;
	for (int i = 0; i < b; i++) {
		n *= a;
	}
	return n;
}

//fraction fraction::operator+(const fraction& fr) const {
//	int n = num_ * fr.den_ + den_ * fr.num_;
//	int d = den_ * fr.den_;
//	return fraction(n, d);
//}


void operator+=(fraction& f1, fraction& f2)
{
	int n = f1.GetNum() * f2.GetDen() + f2.GetNum() * f1.GetDen();
	int d = f1.GetDen() * f2.GetDen();
	f1.SetNum(n);
	f1.SetDen(d);
}
void operator+=(fraction& f1, int& f2) {
	f1 += fraction(f2);
}
void operator+=(fraction& f1, double& f2) {
	f1 += fraction(f2);
}


fraction operator+(fraction& f1, fraction& f2)
{
	int n = f1.GetNum() * f2.GetDen() + f2.GetNum() * f1.GetDen();
	int d = f1.GetDen() * f2.GetDen();
	return fraction(n, d);
}
fraction operator+(fraction& f1, int f2) {
	return f1 + fraction(f2);
}
fraction operator+(fraction& f1, double f2) {
	return f1 + fraction(f2);
}

fraction fraction::operator-(const fraction& fr) const {
	int n = num_ * fr.den_ - den_ * fr.num_;
	int d = den_ * fr.den_;
	return fraction(n, d);
}

fraction fraction::operator*(const fraction& fr) const {
	int n = num_ * fr.num_;
	int d = den_ * fr.den_;
	return fraction(n, d);
}

fraction fraction::operator/(const fraction& fr) const {
	int n = num_ * fr.den_;
	int d = den_ * fr.num_;
	return fraction(n, d);
}