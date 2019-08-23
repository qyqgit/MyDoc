//============================================================================
// Name        : exec03.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 虚析构
//============================================================================

#include <iostream>
using namespace std;
class Base{
public:
	Base(){cout << "Base" << endl;}
	//~Base(){cout << "~Base" << endl;}
	virtual ~Base(){cout << "~Base" << endl;}
};
class Stu:public Base{
public:
	Stu(){cout << "Stu" << endl;}
	~Stu(){cout << "~Stu" << endl;}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Stu* pStu = new Stu();
	delete pStu;

	Base* pBase = new Stu();
	delete pBase;
	return 0;
}
