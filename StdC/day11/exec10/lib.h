#ifndef __LIB_H__
#define __LIB_H__
#include "point.h"
typedef void* (*CALLBACK)(void* pArr);
typedef void* (*CALLBACKEX)(void* pArr, void* pParam);
typedef void* (*CALLBACKXY)(void* pArr, void* pX, void* pY);
typedef void* (*CALLBACKXYEX)(void* pArr, void* pX, void* pY, void* pParam);
void* forEach(void* arr, int size, int count, CALLBACK pFunc);
void* forEachEx(void* arr, int size, int count, CALLBACKEX pFunc, void* pParam);
void* forEachXY(void* arr, int size, int count, int x, int y, CALLBACKXY pFunc);
void* forEachXyEx(void* arr, int size, int count, int x, int y, CALLBACKXYEX pFuncEx, void* pParam);
void goStraightLine(POINT* pPoint, float* pK, int* pB, int* pTurn);
#endif
