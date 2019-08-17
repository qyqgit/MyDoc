//============================================================================
// Name        : exec01.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 初始化表析构函数
//============================================================================

#include <iostream>
using namespace std;
class Human{
public:
	Human(int age = 10, string name = "null_name", float score = 20):h_age(age), h_name(name), h_score(score), h_str("fine."){
		//this->h_score = 0;常数和引用类型需要在初始化表指明初始值
		this->h_str = "good.";
		this->h_num = new double;
		i = 0;
	}
	~Human(){
		cout << "~Human()" << endl;
		delete this->h_num;
	}
	void printHuman(){
		cout << this->h_name;
		cout << ":";
		cout << this->h_age;
		cout << ":";
		cout << this->h_score << ":" << this->h_str;
		cout << "i:" << this->i;
		cout << endl;
	}
	Human&  incI(){
		this->i++;
		return *this;//串联调用
	}
private:
	int h_age;
	string h_name;
	const float h_score;
	string h_str;
	double *h_num;
	int i;
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Human hum;
	hum.printHuman();
	hum.incI().incI().incI();//串联调用
	hum.printHuman();
	return 0;
}
