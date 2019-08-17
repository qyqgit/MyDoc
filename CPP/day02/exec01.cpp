#include <iostream>
using namespace std;

void foo(int a, int b, double c, char d = 'A'){
	cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
}
int main(){
	foo(1, 2, 3.3, 'B');
	foo(3, 4, 4.4);
	return 0;
}
