#include <iostream>
#include <cstdlib>
using namespace std;
int foo(){
	int a = 100;
	return a;
}
struct Student{
	int age;
	char name[256];
};
Student stu_func(){
	Student stu;
	return stu;
}
int main(){
	int a = 10;//具名内存且能够取地址叫左值 无const修饰(非常左值)
	//const int b = 10;//常左值 生命周期为当前作用域的生命周期

	10;//匿名内存->不能取地址->右值->基本类型->常右值 复合类型->非常右值
	//&10;
	foo();
	//&foo();
	stu_func();
	//&stu_func();
	Student st;
	stu_func() = st;
	return 0;
}
