#include <iostream>
#define MAX(x,y) ((x) > (y) ? (x) : (y))
using namespace std;
inline int foo(int x, int y){
	return x > y ? x : y;
}
int main(){
	cout << foo(2, 3) << endl;
	cout << MAX(3 + 4, 4 + 8) << endl;
	return 0;
}
