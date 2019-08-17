#include <iostream>
#include <cstring>
using namespace std;
struct Student{
	int age;
	char name[256];
	void who(){
		cout << name << ":" << age << endl;
	}
};
void struct_func(){
	//struct Student s;
	Student s;
	s.age = 22;
	strcpy(s.name, "zhang");
	cout << s.name << ":" << s.age << endl;
	s.who();
};
void union_func(){
	union{
		//匿名联合
		int i;
		char c[4];
	};
	i = 0x12345678;
	cout << hex << (int)c[0] << ' ' << (int)c[1] << ' ' << (int)c[2] << ' ' << (int)c[3] << endl;
}
enum color{
	red,
	green,
	blue,
};
void enum_func(){
	color c;
	c = blue;
	cout << c << endl;
}
void bool_func(){
	bool true_bool = 0;//true;
	bool false_bool = 1;//false;
	cout << "true_bool  " << true_bool << endl;
	cout << "false_bool " << false_bool << endl;
}
int main(){
	struct_func();
	union_func();
	enum_func();
	bool_func();
}
