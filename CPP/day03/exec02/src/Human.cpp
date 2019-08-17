/*
 * Human.cpp
 *
 *  Created on: 2019年8月14日
 *      Author: vim
 */
#include <iostream>
#include <cstring>
#include "Human.h"
using namespace std;
Human::Human(int h_age, const char *h_name){
	age = h_age;
	strcpy(name, h_name);
}

void Human::printHuman(){
	cout << name << ":" << age << endl;
}



