//============================================================================
// Name        : exec06.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class MyString{
private:
	char *pstrz;
public:

	MyString(const char *pstrz = ""):pstrz(new char[strlen(pstrz) + 1]){
		strcpy(this->pstrz, pstrz);
	}
	MyString(const MyString& myString):pstrz(new char[strlen(myString.pstrz) + 1]){
		strcpy(this->pstrz, myString.pstrz);
	}
	MyString& operator=(const MyString& myString){
		if(this != &myString){
			char* old = this->pstrz;
			this->pstrz = new char[strlen(myString.pstrz) + 1];
			strcpy(this->pstrz, myString.pstrz);
			delete[] old;
		}
		return *this;
	}
	~MyString(){
		delete[] this->pstrz;
	}

	char* getPstrz() const {
		return pstrz;
	}

	void setPstrz(char* pstrz) {
		this->pstrz = pstrz;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	MyString myString("test string01");
	MyString myString2(myString);

	MyString myString3("haha");

	string str("haha");

	myString = myString2;

	string* pStr = new string("fffff");
	delete pStr;

	MyString* pMyStr = new MyString("ggggg");
	delete pMyStr;

	myString = *pMyStr;

	cout << myString.getPstrz() << " " << myString2.getPstrz() << endl;
	return 0;
}
