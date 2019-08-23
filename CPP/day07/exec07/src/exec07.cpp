//============================================================================
// Name        : exec07.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class B : public runtime_error{
public:
	B(int errno, string msg): runtime_error(msg), errno(errno){
	}
public:
	int errno;
};

void foo(){
	throw B(404, "not found.");
}

int main() {
	try{
		foo();
	}catch(B& ex){
		cout << ex.errno << endl;
		cout << ex.what() << endl;
	}
	return 0;
}
