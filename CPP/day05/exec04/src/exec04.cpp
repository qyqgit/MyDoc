//============================================================================
// Name        : exec04.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Object{
public:
	int mass;
};
class Human{
public:
	string name;
	int age;
	int getAge() const {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}

	const string& getName() const {
		return name;
	}

	void setName(const string& name) {
		this->name = name;
	}

	void print(){
		cout << "---human---" << endl;
		cout << "name:" << name << "age:" << age << endl;
		cout << "country:" << country << "race:" << race << endl;
	}
protected:
	string country;
	const string& getCountry() const {
		return country;
	}

	void setCountry(const string& country) {
		this->country = country;
	}
private:
	string race;
	const string& getRace() const {
		return race;
	}

	void setRace(const string& race) {
		this->race = race;
	}
};
class Student : public Human, public Object{
public:
	int id;
	float score;
	void print(){
		cout << "---student---" << endl;
		cout << "name:" << name << "age:" << age << endl;
		cout << "country:" << country << /*"race:" << race <<*/ endl;
	}
	void study(){
		//Human::print();
		print();
		cout << "study..." << endl;
	}
private:
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Human hum;
	Student stu;

	Human* ph = &stu;
	Human& rh = stu;//子类对象可以是基类对象

	Student* pstu = static_cast<Student*>(ph);//强转不建议
	Student& rstu = static_cast<Student&>(rh);//强转不建议

	stu.setAge(22);
	stu.setName("sun ");
	//stu.setCountry("cn");类的对象不能访问protected成员，但类的成员函数是可以访问protected成员的
	stu.print();
	stu.Human::print();
	return 0;
}
