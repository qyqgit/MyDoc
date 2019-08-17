//============================================================================
// Name        : exec03.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Dog{
public:
	Dog(const string& name){
		this->name = name;
	}
	/*Dog(const Dog& dog){//如果没有拷贝构造函数，则默认提供拷贝构造函数

	}*/
	const Dog& operator=(const Dog& dog){
		this->name = "dongdongDog";
		return dog;
	}
	void talk(){
		cout << this->name <<" wang wang." << endl;
	}

	const string& getName() const {
		return name;
	}

	void setName(const string& name) {
		this->name = name;
	}

private:
	string name;
	friend class Cat;//友元
};
class Cat{
public:
	Cat(const string& name){//也是类型转换构造，如类型一样是拷贝构造
		this->name = name;
	}
	//Cat(const Dog& dog){//类型转换构造
	explicit Cat(const Dog& dog){//explicit关键字构造函数必须强制转换
		this->name = dog.name;//友元
	}
	void talk(){
		cout << this->name <<" miao miao." << endl;
	}
private:
	string name;
	//friend class Dog;//友元
};

class Human{
public :
	//如果未提供任何构造函数，则编译器自动提供一个无参构造
	//如有构造函数，则不提供无参构造函数
	Human(){
		age = 0;
		name = "null_name";
	}
	Human(int age){
		this->age = age;
	}
	Human(int age, string name){
		this->age = age;
		this->name = name;
	}

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

private:
	int age;
	string name;
};
int main() {
	Human hum;
	cout << hum.getAge() << endl;
	cout << hum.getName() << endl;

	Human hum2(33, "dong");
	cout << hum2.getAge() << endl;
	cout << hum2.getName() << endl;
	cout << "+++++++++++++++++" << endl;
	Dog dog("dog");
	dog.talk();
	Cat cat("cat");
	cat.talk();

	Dog testDog = Dog("testDog");
	testDog.talk();
	Cat testCat = Cat("testCat");
	testCat.talk();
	cout << "+++++++++++++++++" << endl;
	Cat testCat2 = Cat(testDog);//dog -> cat
	testCat2.talk();
	Cat testCat3 = static_cast<Cat>(testDog);//dog -> cat
	testCat3.talk();

	Dog testDog2 = static_cast<Dog>("testDog2");//string -> dog
	testDog2.talk();

	Dog cpDog = Dog(testDog);//拷贝构造
	cpDog.talk();

	cpDog = testDog;//拷贝赋值函数，如果编译器没有提供，则编译器提供一个
	cpDog.talk();

	Cat testCat555(testDog);//dog -> cat
	testCat555.talk();
	//Cat testCat666 = testDog;//explicit
	Cat testCat666 = static_cast<Cat>(testDog);
	testCat666.talk();
	return 0;
}
