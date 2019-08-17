//============================================================================
// Name        : exec03.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 流运算符重载
//============================================================================

#include <iostream>
using namespace std;
class Complex{
public:
	Complex(int s = 0, int x = 0):m_s(s), m_x(x){
	}
	void print(){
		cout << m_s << "+" << m_x << "i" << endl;
	}
private:
	int m_s;
	int m_x;
	friend ostream& operator<<(ostream& os, const Complex& complex);
	friend istream& operator>>(istream& is, Complex& complex);
};
ostream& operator<<(ostream& os, const Complex& complex){
	os << complex.m_s << "+" << complex.m_x << "i";
	return os;
}
istream& operator>>(istream& is, Complex& complex){
	is >> complex.m_s >> complex.m_x;
	return is;
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Complex a(1, 2);
	cout << a << endl;//::operator<<(cout,a)
	cin >> a;
	cout << a << endl;
	return 0;
}
