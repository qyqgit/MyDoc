/*
 * exec05.cpp
 *
 *  Created on: 2019年8月13日
 *      Author: vim
 */
#include <iostream>
using namespace std;

int g_val = 10;

int& foo_refer(){
	return g_val;
}

int& foo_refer2(){
	static int s_val = 123;
	return s_val;
}

int& foo_refer3(){
	static int* p = new int;
	return *p;
}

int foo(){
	return 100;
}
void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(int& a, int& b){
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
int main(){
	int a = 10;
	int& r_a = a;
	cout << r_a << endl;

	const int& cr_a = a;
	//cr_a = 3;
	cout << cr_a << endl;

	const int& r_10 = 10;//常引用延长无名内存的生命周期
	const int& r_foo = foo();//常引用延长无名内存的生命周期
	cout << r_10 << r_foo << endl;

	int aa = 22;
	int bb = 33;
	swap(aa, bb);
	swap(&aa, &bb);
	cout << aa;
	cout << " ";
	cout << bb;
	cout << endl;

	foo_refer() = 100;
	cout << g_val << endl;
	foo_refer2() = 321;
	cout << foo_refer2() << endl;
	foo_refer3() = 222;
	cout << foo_refer3() << endl;

}


