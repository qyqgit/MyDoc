//============================================================================
// Name        : exec06.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A{
public:
	~A(){
		throw -1;//析构里抛异常 不建议 在析构里处理异常
	}
};
void hum(){
	throw -2;
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	try{
		A a;
		//hum();栈的辗转开解
	}catch(int& ex){
		cout << "ex" << endl;
	}
	return 0;
}
