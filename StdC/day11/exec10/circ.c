#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "stdout.h"
#include "circ.h"
void fillCirc(char* pPixel, int* pX, int* pY, CIRC* pCirc){
	if((*pX - pCirc->point.x) * (*pX - pCirc->point.x) + (*pY - pCirc->point.y) * (*pY - pCirc->point.y) < pCirc->r * pCirc->r){
		POINT point;
		point.x = *pX;
		point.y = *pY;
		writePoint(&point);
	}	
}
void writeCirc(CIRC* pCirc){
	forEachXyEx(gScreenBuff, sizeof(gScreenBuff[0][0]), WIDTH * HEIGHT, WIDTH, HEIGHT, (CALLBACKXYEX) fillCirc, pCirc);
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

CIRC_PROTOCOL* getCircProtocolMalloc(){
	CIRC_PROTOCOL* pCircProtocol = (CIRC_PROTOCOL*)malloc(sizeof(CIRC_PROTOCOL));
	if(!pCircProtocol)
		return NULL;
	pCircProtocol->getCircMalloc 	= getCircMalloc;
	pCircProtocol->writeCirc	= writeCirc;
	return pCircProtocol;
}
