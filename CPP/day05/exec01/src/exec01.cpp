//============================================================================
// Name        : exec04.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 运算符重载
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
	const Complex operator+(const Complex& b)const/*a常属性修饰*/{//b可能是左值也可能时右值，所以const万能引用
		return Complex(m_s + b.m_s, m_x + b.m_x);
	}
	Complex sub(const Complex& that){
		return Complex(m_s - that.m_s, m_x - that.m_x);
	}
//	const Complex operator-(const Complex& b)const/*a常属性修饰*/{//b可能是左值也可能时右值，所以const万能引用
//		return Complex(m_s - b.m_s, m_x - b.m_x);
//	}*/
	void print(){
		cout << m_s << "+" << m_x << "i" << endl;
	}
private:
	int m_s;
	int m_x;
	friend const Complex operator-(const Complex& l, const Complex& r);
};
const Complex operator-(const Complex& l, const Complex& r){
	return Complex(l.m_s - r.m_s, l.m_x - r.m_x);
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Complex a(1, 2), b(3, 4), c(5, 6);

	//Complex re = a.sum(b);
	Complex re = a + b;

	re.print();

	//re = a.sub(b);
	re = a - b;

	re.print();
	return 0;
}
