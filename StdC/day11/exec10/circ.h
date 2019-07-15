#ifndef __CIRC_H__
#define __CIRC_H__
#include "point.h"
typedef struct circ{
	POINT 	point;
	int	r;
} CIRC;

typedef CIRC* (*GET_CIRC_MALLOC)(POINT* pPoint, int r);
typedef void (*PRINT_CIRC)(CIRC* pCirc);

typedef struct circ_protocol{
	GET_CIRC_MALLOC			getCircMalloc;
	PRINT_CIRC			writeCirc;
} CIRC_PROTOCOL;

void		writeCirc(CIRC* pCirc);
CIRC*		getCircMalloc(POINT* pPoint, int r);
CIRC_PROTOCOL*	getCircProtocolMalloc();
#endif
