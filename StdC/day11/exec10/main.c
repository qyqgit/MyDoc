#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "point.h"
#include "circ.h"
#include "stdout.h"
void print_int(int* i){
	printf("%d\n", *i);
}
void print_double(double* i){
	printf("%lg\n", *i);
}
int main(void){
	POINT		point1;
	POINT		point2;
	int 		r1 = 5;
	int		r2 = 5;
	point1.x 	= 20;
	point1.y 	= 15;
	CIRC* 		pCirc1;
	CIRC* 		pCirc2;
	CIRC_PROTOCOL*	pCircProtocol;

	float k1 = 1;
	float k2 = 1;
	int b1 = 0;
	int b2 = 0;
	int turn1 = 0;
	int turn2 = 0;

	scanf("%d%d", &point2.x, &point2.y);
	scanf("%d", &r2);
	k2 = (float)point2.y/(float)point2.x;
	while(1){
		initScreen();
		showImage("background.dat");
		goStraightLine(&point1, &k1, &b1, &turn1);
		goStraightLine(&point2, &k2, &b2, &turn2);

		pCirc1 = getCircMalloc(&point1, r1);
		pCirc2 = getCircMalloc(&point2, r2);
		pCircProtocol = getCircProtocolMalloc();
		pCircProtocol->writeCirc(pCirc1);
		pCircProtocol->writeCirc(pCirc2);

		showScreen();
		free(pCircProtocol);
		free(pCirc1);
		free(pCirc2);
		pCircProtocol = NULL;
		pCirc1 = NULL;
		pCirc2 = NULL;
		sleep(1);
		screenShot();
	}
	return 0;
}
