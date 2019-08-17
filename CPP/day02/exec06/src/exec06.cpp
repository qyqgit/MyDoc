//============================================================================
// Name        : exec06.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//任何基本类型的变量之间都可以隐式转换

	//任何类型的指针都可以和void*做隐式转换
	//void*和任何类型指针都必须强转

	//任何类型的指针都可以和同类型的常指针做隐式转换
	//任何类型的常指针和同类型的指针都必须强转

	//除了void*外，其他任何类型指针之间必须强转
	int		i;
	double	d;
	float	f;
	char	c;
	short	s;

	//任何基本类型的变量之间都可以隐式转换
	i = d = f = c = s;
	s = c = f = d = i;
	//任何类型的指针都可以和void*做隐式转换
	void* pv = NULL;
	pv = &i;
	pv = &d;
	pv = &f;
	pv = &c;
	pv = &s;
	//void*和任何类型指针都必须强转
	int		*pi = static_cast<int*>(pv);//原类型和目标类型只要在一个方向上可以做隐式转换，那么在两个方向上都可以做静态类型转换
	double 	*pd = static_cast<double*>(pv);
	float 	*pf = static_cast<float*>(pv);
	char 	*pc = static_cast<char*>(pv);
	short 	*ps = static_cast<short*>(pv);

	//任何类型的指针都可以和同类型的常指针做隐式转换
	const int* 		cpi = pi;
	const double*	cpd = pd;
	const float*	cpf = pf;
	const char*		cpc = pc;
	const short*	cps = ps;

	//任何类型的常指针和同类型的指针都必须强转
	pi = const_cast<int*>(cpi);//编译器检查原类型与目标类型是否同为指针或引用，且目标类型之间除常属性以外必须完全相同
	pd = const_cast<double*>(cpd);
	pf = const_cast<float*>(cpf);
	pc = const_cast<char*>(cpc);
	ps = const_cast<short*>(cps);

	//除了void*外，其他任何类型指针之间必须强转
	pi = reinterpret_cast<int*>(pd);//任意类型指针或引用之间转换
	int addr = reinterpret_cast<int>(pi);
	pc = reinterpret_cast<char*>(0xffff0000);
	cout << "!!!Hello World!!!" << addr << (int)pi << endl; // prints !!!Hello World!!!
	return 0;
}
