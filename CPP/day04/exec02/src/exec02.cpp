//============================================================================
// Name        : exec02.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 常函数常对象 深拷贝浅拷贝
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class Integer{
public:
	Integer(int i = 0){
		this->i = i;
	}
	void printInteger(/*const Integer* this*/)const{//常函数内部无法修改成员变量的值
		cout << "const" << endl;
		//this->i = 3;
		const_cast<Integer*>(this)->i = 3;//mutable
		cout << i << endl;
	}
	void printInteger(/*Integer* this*/){//非常函数
		cout << "no const" << endl;
		this->i = 4;
		cout << i << endl;
	}
private:
	int i;
	//mutable int i;//const_cast<>
};
class String{
public:
	String(const char *pstrz = ""):pstrz(new char[strlen(pstrz) + 1]){
		strcpy(this->pstrz, pstrz);
	}
	/*String (const String& string){
		//默认拷贝构造会有浅拷贝问题
	}*/
	String(const String& string):pstrz(new char[strlen(string.pstrz) + 1]){
		strcpy(this->pstrz, string.pstrz);//深拷贝
	}
	String& operator=(const String& that){
		if(this != &that){//防止自赋值
			char* old = this->pstrz;
			this->pstrz = new char[strlen(that.pstrz) + 1];//申请新资源
			strcpy(this->pstrz, that.pstrz);//拷贝新内容
			delete[] old;//释放旧资源
		}
		return *this;//返回自引用
	}
	~String(){
		cout << this->pstrz << ":" << (int)pstrz << endl;
		delete[] this->pstrz;
	}
	void printString(){
		cout << this->pstrz << endl;
	}
private:
	char *pstrz;
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Integer i;
	i.printInteger();
	const Integer ci;//常对象
	ci.printInteger();//常对象调用常函数

	String str;
	str.printString();

	String str2("string2");
	str2.printString();

	String str3 = "string3";
	str3.printString();
	cout << "-------------" << endl;
	String str4 = str3;
	str4.printString();
	cout << "-------------" << endl;
	return 0;
}
