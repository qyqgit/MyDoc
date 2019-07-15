#ifndef __POINT_H__
#define __POINT_H__
typedef struct point{
	int x;
	int y;
} POINT;

typedef POINT* (*GET_POINT_MALLOC)();
typedef void (*WRITE_POINT)(POINT *point);

typedef struct point_protocol{
	POINT			point;
	GET_POINT_MALLOC 	getPointMalloc;
	WRITE_POINT		writePoint;
} POINT_PROTOCOL;
void writePoint(POINT* pPoint);
#endif
