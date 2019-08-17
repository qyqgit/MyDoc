//============================================================================
// Name        : exec03.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 静态成员 单例模式
//============================================================================

#include <iostream>
using namespace std;
class Singleton_{//饿汉式
public:
	static Singleton_& getInstance(){
		if(!instance)//mutex锁？
			instance = new Singleton_;//mutex锁？
		counter++;//mutex锁？
		return *instance;
	}
	void releaseInstance(){
		if(--counter == 0)
			delete this;
	}
private:
	Singleton_(){
		cout << "Singleton invoked." << endl;
	}
	Singleton_(const Singleton_& that){}
	static Singleton_ *instance;
	static int counter;//信号量？
	~Singleton_(){
		cout << "~Singleton invoked." << endl;
		instance = NULL;
	}
};
Singleton_* Singleton_::instance = NULL;
int Singleton_::counter = 0;

class Singleton{//饿汉式
public:
	static Singleton& getInstance(){
		return instance;
	}

private:
	Singleton(){}
	Singleton(const Singleton& that){}
	static Singleton instance;
};
Singleton Singleton::instance;
class A{
public:
	static int a;//静态成员变量不在对象中，数据段
	static void foo(){
		//cout << this << endl;无this指针，也无const属性
	}
	void bar(){
	}
private:
	double b;
};
int A::a = 233;
int main() {
	A a;
	A::foo();
	//A::bar();
	A::a = 44;
	//A::b = 33;
	a.foo();
	a.bar();
	//a.b = 33.0;
	cout << sizeof(a) << ":" << a.a << endl;
	//cout << sizeof(a) << a.b << endl;
	cout << "-----------------------------" << endl;
	//Singleton s1, s2, s3;
	//cout << (int)s1 << ":" << (int)s2 << ":" << (int)s3 << endl;
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();
	Singleton& s3 = Singleton::getInstance();
	cout << &s1 << ":" << &s2 << ":" << &s3 << endl;

	//Singleton_ s_1, s_2, s_3;
	Singleton_& s_1 = Singleton_::getInstance();
	Singleton_& s_2 = Singleton_::getInstance();
	Singleton_& s_3 = Singleton_::getInstance();
	s_1.releaseInstance();
	s_2.releaseInstance();
	s_3.releaseInstance();
	cout << &s_1 << ":" << &s_2 << ":" << &s_3 << endl;
	return 0;
}
