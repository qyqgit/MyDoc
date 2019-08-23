//============================================================================
// Name        : exec03.cpp
// Author      : vim
// Version     :
// Copyright   : Your copyright notice
// Description : 对象的自恰
//============================================================================

#include <iostream>
using namespace std;
class Shape{
public:
	Shape(int x, int y):x(x), y(y){

	}
	//virtual void Draw(){
	void Draw(){
		cout << "Shape::Draw()" << endl;
	}
private:
	int x;
	int y;
};
class Rect: public Shape{
public:
	Rect(int lx, int ly, int rx, int ry):Shape(lx, ly), rx(rx), ry(ry){

	}
	void Draw(){
		cout << "Rect::Draw()" << endl;
	}
private:
	int rx;
	int ry;
};
class Circle: public Shape{
public:
	Circle(int x, int y, int r):Shape(x, y),r(r){

	}
	void Draw(){
		cout << "Circle::Draw()" << endl;
	}
private:
	int r;
};
int main() {
	Shape s(100, 100);
	s.Draw();

	Rect r(300, 300, 300, 300);
	r.Draw();

	Circle c(300, 300, 50);
	c.Draw();

	Shape* ps = &r;
	ps->Draw();

	Shape* ps2 = &c;
	ps2->Draw();

	return 0;
}
