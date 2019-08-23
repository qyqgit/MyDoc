//============================================================================
// Name        : exec04.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;
class A{
public:
	A(){
		cout << "A()" << endl;
		m_p = new int;
	}
	~A(){
		cout << "~A()" << endl;
		delete m_p;
	}
private:
	int* m_p;
};
int foo(){
	A a;
	cout << "---foo---" << endl;
	FILE* pFile = fopen("server", "r");
	if(!pFile)
		throw "file open fail.";
	cout << "!!!foo!!!" << endl;
	return 0;
}
int foo_return(){
	A a;
	cout << "---foo_return---" << endl;
	FILE* pFile = fopen("server", "r");
	if(!pFile)
		return -1;
	cout << "!!!foo_return!!!" << endl;
	return 0;
}
int bar(){
	A a;
	cout << "---bar---" << endl;
//	try{
//		foo();
//	}catch (const char* ex){
//		cout << ex << endl;
//	};
	foo_return();
	cout << "!!!bar!!!" << endl;
	return 0;
}
int main() {
	//如果程序没有捕获异常的代码，系统将获取异常，
	//直接结束程序(函数右花括号不被执行)，所有局部对象丧失析构机会

	bar();
	return 0;
}
