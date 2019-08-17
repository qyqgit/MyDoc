#include <iostream>
using namespace std;
void foo(int){
	cout << "foo(int)" << endl;
}
void foo(){
	cout << "foo" << endl;
}
int main(){
	foo(10);
	return 0;
}
