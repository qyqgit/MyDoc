#include <stdio.h>
#include <stdlib.h>
#include "circ.h"

void printCirc(CIRC* circ){
	printf("circ_%d_%d_%d\n", circ->point.x, circ->point.y, circ->r);
}

CIRC* getCircMalloc(POINT* pPoint, int r){
	if(!pPoint)
		return NULL;
	CIRC* pCirc = (CIRC*)malloc(sizeof(CIRC));
	if(!pCirc)
		return NULL;
	pCirc->point.x = pPoint->x;
	pCirc->point.y = pPoint->y;
	pCirc->r = r;
	return pCirc;
}

CIRC_PROTOCOL* getCircProtocolMalloc(CIRC* pCirc){
	if(!pCirc)
		return NULL;
	CIRC_PROTOCOL* pCircProtocol = (CIRC_PROTOCOL*)malloc(sizeof(CIRC_PROTOCOL));
	if(!pCircProtocol)
		return NULL;
	pCircProtocol->circ		= *pCirc;
	pCircProtocol->getCircMalloc 	= getCircMalloc;
	pCircProtocol->printCirc	= printCirc;
	return pCircProtocol;
}
