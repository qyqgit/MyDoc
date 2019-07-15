#include "stdout.h"
#include "point.h"
void writePoint(POINT* pPoint){
	gScreenBuff[pPoint->y][pPoint->x] = '0';
}
