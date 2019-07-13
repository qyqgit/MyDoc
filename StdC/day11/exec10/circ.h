#ifndef __CIRC_H__
#define __CIRC_H__
#include "point.h"
typedef struct circ{
	POINT 	point;
	int	r;
} CIRC;

typedef CIRC* (*GET_CIRC_MALLOC)(POINT* pPoint, int r);
typedef void (*PRINT_CIRC)(CIRC* circ);

typedef struct circ_protocol{
	CIRC				circ;
	GET_CIRC_MALLOC			getCircMalloc;
	PRINT_CIRC			printCirc;
} CIRC_PROTOCOL;

void		printCirc(CIRC* circ);
CIRC*		getCircMalloc(POINT* pPoint, int r);
CIRC_PROTOCOL*	getCircProtocolMalloc(CIRC* pCirc);
#endif
