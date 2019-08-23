//============================================================================
// Name        : exec04.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A{
public:
	virtual void foo(){
		cout << "A::foo()" << endl;
	}
	virtual void bar(){
		cout << "A::bar()" << endl;
	}
	void print(){
		foo();
	}
};
class B:public A{
public:
	virtual void foo(){
		cout << "B::foo()" << endl;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	B b;
	A* pa = &b;
	pa->print();
	cout << "-----------------" << endl;
	void(**pFunc)() = *((void(***)())&b);
	pFunc[0]();
	pFunc[1]();

	return 0;
}
