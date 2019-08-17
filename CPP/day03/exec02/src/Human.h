/*
 * Human.h
 *
 *  Created on: 2019年8月14日
 *      Author: vim
 */

#ifndef HUMAN_H_
#define HUMAN_H_
class Human{
public:
	Human(int h_age = 0, const char * h_name = "null_name");
	void printHuman();
private:
	int age;
	char name[256];
};




#endif /* HUMAN_H_ */
