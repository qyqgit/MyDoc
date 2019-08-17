#include <iostream>
using namespace std;
namespace ns1{
	void foo(char* c, short s){
		cout << 1 <<endl;
	}
	void foo(double c, int s){
		cout << 2 <<endl;
	}
}
namespace ns2{
	void foo(const char* c, short s){
		cout << 3 <<endl;
	}
	void foo(int c, double s){
		cout << 4 <<endl;
	}
}
void foo(char* c, short s){
	cout << "1:foo(char*, short)" << endl;//_Z3fooPcs

}
void foo(const char* c, short s){
	cout << "2:foo(const char*, short)" << endl;//_Z3fooPKcs
}
int main(){
	char* c;
	const char* cc;
	short s;
	foo(c, s);
	foo(cc, s);
	void (*pFunc)(const char*, short) = foo;//根据函数指针类型选定
	pFunc(c, s);
	return 0;
}
