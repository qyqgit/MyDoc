//============================================================================
// Name        : exec02.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>

using namespace std;

class A{
public:
	virtual void foo(){}
	//void foo(){}
	virtual ~A(){}//虚析构
};
class B:public A{};

int main() {
	int a;
	double b;
	float c;
	short d;
	char e;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;
	cout << typeid(int).name() << endl;

	B bb;
	A* pa = &bb;
	cout << typeid(*pa).name() << endl;
	return 0;
}
