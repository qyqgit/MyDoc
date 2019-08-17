//============================================================================
// Name        : exec01.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class Human{//struct访问限制符默认puclic，class访问限制符默认private
public:
	int age;
	Human(int c_age = 0, const char *c_name = "null_name"){
		cout << "humman construct\n";
		this->age = c_age;
		strcpy(this->name, c_name);

	}
	void setName(char *str){
		strcpy(this->name, str);
	}
	char* getName(){
		return name;
	}

	int getAge() const {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}
	void printHuman(Human human);
	void printHuman();

private:
	char name[256];
};
void Human::printHuman(Human human){
	cout << "name:" << human.getName() << endl;
	cout << "age:" << human.age << endl;
}
void Human::printHuman(){
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
}
int main() {
	Human human(222, "wang");
	cout << "line num 47" << endl;
	cout << human.age << endl;
	cout << human.getName() << endl;
	human.age = 22;
	human.setName("zhao");
	cout << human.getName();
	cout << ":";
	cout << human.age;
	cout << endl;

	Human hum;
	hum.printHuman(hum);

	Human hum_array[8];
	for (int i = 0; i < 8; i++){
		cout << "------" << endl;
		hum_array[i].printHuman(hum_array[i]);
		hum.printHuman(hum_array[i]);
		cout << "------" << endl;
	}
	Human hum_array2[3] = {Human(11, "zhao"), Human(22, "qian"), Human(33, "sun")};
	for (int i = 0; i < 3; i++){
		hum.printHuman(hum_array2[i]);
	}
	cout << "++++++++++++++++++++++" << endl;
	Human* phum = new Human;
	phum->printHuman();
	delete phum;

	Human* phum2 = new Human(22, "zhou");
	phum2->printHuman();
	delete phum2;

	Human* phum3 = new Human[3];
	for(int i = 0; i < 3; i++){
		phum3[i].printHuman();
	}
	delete[] phum3;

	Human* phum4 = new Human[2]{Human(33, "wu"), Human(44, "zheng")};
	for(int i = 0; i < 2; i++){
		phum4[i].printHuman();
	}
	delete[] phum4;
	return 0;
}
