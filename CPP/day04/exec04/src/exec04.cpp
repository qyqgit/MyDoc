//============================================================================
// Name        : exec04.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Complex{
public:
	Complex(int s = 0, int x = 0):m_s(s), m_x(x){

	}
	Complex sum(const Complex& that){
		return Complex(m_s + that.m_s, m_x + that.m_x);
	}
	Complex sub(const Complex& that){
		return Complex(m_s - that.m_s, m_x - that.m_x);
	}
	void print(){
		cout << m_s << "+" << m_x << "i" << endl;
	}
private:
	int m_s;
	int m_x;
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Complex a(1, 2), b(3, 4), c(5, 6);
	Complex re = a.sum(b);
	re.print();
	re = a.sub(b);
	re.print();
	return 0;
}
