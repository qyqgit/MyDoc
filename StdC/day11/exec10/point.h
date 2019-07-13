#ifndef __POINT_H__
#define __POINT_H_
typedef struct point{
	int x;
	int y;
} POINT;

typedef POINT* (*GET_POINT_MALLOC)();
typedef void (*PRINT_POINT)(POINT *point);

typedef struct point_protocol{
	POINT			point;
	GET_POINT_MALLOC 	getPointMalloc;
	PRINT_POINT		printPoint;
} POINT_PROTOCOL;
#endif
