//============================================================================
// Name        : exec02.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 赋值拷贝 操作符重载
//============================================================================

#include <iostream>
using namespace std;
class Complex{
public:
	Complex(int s = 0, int x = 0):m_s(s), m_x(x){
	}
	const Complex operator-()const{
		return Complex(-m_s, -m_x);
	}
	const Complex operator~()const{
		return Complex(~m_s, ~m_x);
	}
	const Complex operator++(int){//b++
		Complex old = *this;
		++m_s;
		++m_x;
		return old;//和基本数据类型一致性原则
	}
	Complex& operator++(){//++b
		++m_s;
		++m_x;
		return *this;
	}
	Complex& operator=(const Complex& r){
		m_s = r.m_s;
		m_x = r.m_x;
		return *this;
	}
	Complex& operator+=(const Complex& r){
		m_s += r.m_s;
		m_x += r.m_x;
		return *this;
	}
	bool operator==(const Complex& r)const{
		return m_x == r.m_x && m_s == r.m_s;
	}
	bool operator!=(const Complex& r)const{
		return !(*this == r);
	}
	void print(){
		cout << m_s << "+" << m_x << "i" << endl;
	}
private:
	int m_s;
	int m_x;
	friend const Complex operator-(const Complex& l, const Complex& r);
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Complex a(1, 2), b(2, 3), c(3, 4);
	a = b;
	a.print();

	a += b = c;
	a.print();

	c = -c;//c.operator-()
	c.print();

	b = ~b;
	b.print();

	++b;//b.operator++()
	b.print();
	b++;//b.operator++(3.1415926)
	b.print();
	return 0;
}
