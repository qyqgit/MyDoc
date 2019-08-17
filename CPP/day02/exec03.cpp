#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	void* p = malloc(4);
	cout << *(int*)p << endl;
	free(p);

	int* p_int = new int;
	cout << *p_int << endl;
	delete p_int;

	int* p_int2 = new int(100);
	cout << *p_int2 << endl;
	delete p_int2;

	int* p_int3 = new int[4];
	for(int i = 0; i < 4; i++){
		cout << p_int3[i] << endl;
	}
	delete[] p_int3;

	int* p_int4 = new int[4]{1, 2, 3, 4};
	for(int i = 0; i < 4; i++){
		cout << p_int4[i] << endl;
	}
	delete[] p_int4;
	
	int (*p_int5)[4] = new int[3][4];
	delete[] p_int5;

	try{
		new char[1000 * 1000 * 1000 * 3];
	}catch(bad_alloc & ex){
		cerr << "bad_alloc" << endl;
		exit(-1);
	}
	return 0;
}
