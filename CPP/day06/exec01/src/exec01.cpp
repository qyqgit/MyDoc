//============================================================================
// Name        : exec01.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Human{
private:
	int age;
	string name;
public:
	Human(int age = 0, string name = "null_name"):age(age), name(name){
		cout << "Human()" << endl;
	}
	~Human(){
		cout << "~Human()" << endl;
	}
	void print(){
		cout << age << " " << name << endl;
	}
};
class Student : public Human{
public:
	Student(float score = 0, string str = "null_str"): score(score), str(str){
		cout << "Student()" << endl;
	}
	Student(int age = 0, string name = "null_name", float score = 0, string str = "null_str"):Human(age, name), score(score), str(str){
		cout << "Student()" << endl;
	}
	void print(){
		Human::print();
		cout << score << " " << str << endl;
	}
	~Student(){
		cout << "~Student()" << endl;
	}
private:
	float score;
	string str;
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Student stu1(22, "zheng.");
	stu1.print();

	Student stu2(float(2.2), "good.");
	stu2.print();

	Student stu3(21, "zhao", 33.33, "fine.");
	stu3.print();

	Student stu4();
	//stu4.print();

	Student* pStu = new Student(22, "");
	delete pStu;
	return 0;
}
