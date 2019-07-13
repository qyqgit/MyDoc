#include <stdio.h>
#include <stdlib.h>
#include "circ.h"
int main(void){
	POINT		point;
	int 		r = 5;
	point.x 	= 2;
	point.y 	= 2;
	CIRC* 		pCirc;
	CIRC_PROTOCOL*	pCircProtocol;
	
	pCirc		= getCircMalloc(&point, r);
	pCircProtocol	= getCircProtocolMalloc(pCirc);
	pCircProtocol->printCirc(pCirc);
	free(pCirc);
	free(pCircProtocol);
	return 0;
}
