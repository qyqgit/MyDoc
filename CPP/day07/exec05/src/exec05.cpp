//============================================================================
// Name        : exec05.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;
void foo() throw(int, double, float){}
void foof() throw(){}//不会抛出任何类型异常

class A{
public:
	A(){
		cout << "A()" << endl;
		a = new int;
	}
	~A(){
		cout << "~A()" << endl;
		delete a;
	}
private:
	int* a;
};
class B{
public:
	B(){
		cout << "B()" << endl;
		b = new int;
	}
	~B(){
		cout << "~B()" << endl;
		delete b;
	}
private:
	int * b;
};
class Server{
public:
	Server(){
		cout << "Server()" << endl;
		//造型内存空间，并赋初值
		FILE* pFile = fopen("server", "r");
		if(!pFile)
			//delete b;
			throw -1;
	}
	~Server(){
		cout << "~Server()" << endl;
	}
private:
	A a;
	B b;
	//B *b;
};
int main() {
	try{
		Server s;
	}catch(int& ex){
		cout << "int" << endl;
	}catch(double& ex){
		cout << "double" << endl;
	}catch(float& ex){
		cout << "float" << endl;
	}
	return 0;
}
