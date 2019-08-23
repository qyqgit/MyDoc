//============================================================================
// Name        : exec02.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Student{
public:
	Student(int score = 0) : score(score){
		cout << "Student()" << endl;
	}
	~Student(){
		cout << "~Student()" << endl;
	}
public:
	int score;
};
class Human{
public:
	Human(int race = 0) : race(race){
		cout << "Human()" << endl;
	}
	~Human(){
		cout << "~Human()" << endl;
	}
public:
	int race;
};
class Object{
public:
	Object(int mass = 0) : mass(mass){
		cout << "Object()" << endl;
	}
	~Object(){
		cout << "~Object()" << endl;
	}
public:
	int mass;
};
class Me: public Student, public Human, public Object{
public:
	Me(int hobby = 0) : hobby(hobby){
		cout << "Me()" << endl;
	}
	~Me(){
		cout << "~Me()" << endl;
	}
private:
	int hobby;
};

int main() {
	Me me;
	cout << &me << endl;
	cout << "!!!隐式转换!!!" << endl; // prints !!!Hello World!!!
	Student* pStu = &me;
	cout << pStu << endl;
	Human* pHum = &me;
	cout << pHum << endl;
	Object* pObj = &me;
	cout << pObj << endl;
	//将继承自多个基类的子类类型的指针，隐式或者静态转换为它的基类类型，
	//编译器会根据各个基类子对象在子类对象中的内存布局，进行适当的偏移运算，
	//以保证指针的类型与其所指向目标对象的类型一致
	cout << "!!!static_cast<>!!!" << endl;
	pStu = static_cast<Student*>(&me);
	cout << pStu << endl;
	pHum = static_cast<Human*>(&me);
	cout << pHum << endl;
	pObj = static_cast<Object*>(&me);
	cout << pObj << endl;
	//将继承自多个基类的子类类型的指针，隐式或者静态转换为它的基类类型，
	//编译器会根据各个基类子对象在子类对象中的内存布局，进行适当的偏移运算，
	//以保证指针的类型与其所指向目标对象的类型一致
	cout << "!!!reinterpret_cast<>!!!" << endl;
	pStu = reinterpret_cast<Student*>(&me);
	cout << pStu << endl;
	pHum = reinterpret_cast<Human*>(&me);
	cout << pHum << endl;
	pObj = reinterpret_cast<Object*>(&me);
	cout << pObj << endl;
	//重解释类型转换都不进行任何偏移计算
	return 0;
}
