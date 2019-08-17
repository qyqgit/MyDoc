//============================================================================
// Name        : exec05.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Base{
public:
	int public_i;
protected:
	int protected_i;
private:
	int private_i;
};
class Father_public : public Base{
public:
	void test(){
		this->public_i = 2;
		this->protected_i = 3;
		//this->private_i = 4;
	}
};
class Son_public : public Father_public{
public:
	void test(){
		this->public_i = 2;
		this->protected_i = 3;
		//this->private_i = 4;
	}
};
class Father_protected : protected Base{
public:
	void test(){
		this->public_i = 2;
		this->protected_i = 3;
		//this->private_i = 4;
	}

};
class Son_protected : protected Father_protected{
public:
	void test(){
		this->public_i = 2;
		this->protected_i = 3;
		//this->private_i = 4;
	}
};
class Father_private : private Base{
public:
	void test(){
		this->public_i = 2;
		this->protected_i = 3;
		//this->private_i = 4;
	}

};
class Son_private : private Father_private{
public:
	void test(){
		//this->public_i = 2;
		//this->protected_i = 3;
		//this->private_i = 4;
	}
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
