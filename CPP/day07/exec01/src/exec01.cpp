//============================================================================
// Name        : exec01.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

class A{
public:
	virtual void foo(){}
};
class B:public A{};
class C:public B{};
class D{};

int main() {
	B b;
	A* pa = &b;
	cout << "pa:" << pa << endl;

	cout << "dynamic_cast<>" << endl;
	B* pb = dynamic_cast<B*>(pa);//需要虚函数
	cout << "pb:" << pb << endl;
	C* pc = dynamic_cast<C*>(pa);
	cout << "pc:" << pc << endl;
	D* pd = dynamic_cast<D*>(pa);
	cout << "pd:" << pd << endl;

	cout << "static_cast" << endl;
	pb = static_cast<B*>(pa);
	cout << "pb:" << pb << endl;
	pc = static_cast<C*>(pa);
	cout << "pc:" << pc << endl;
	//pd = static_cast<D*>(pa);
	//cout << "pd:" << pd << endl;
	cout << "reinternept_cast<>" << endl;
	pd = reinterpret_cast<D*>(pa);
	cout << "pd:" << pd << endl;
	return 0;
}
