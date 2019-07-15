#include "point.h"
#include "lib.h"
void* forEach(void* arr, int size, int count, CALLBACK pFunc){
	int i = 0;
	for(i = 0; i < count; i++){
		pFunc(arr + i * size);
	}
}
void* forEachEx(void* arr, int size, int count, CALLBACKEX pFunc, void* pParam){
	int i = 0;
	for(i = 0; i < count; i++){
		pFunc(arr + i * size, pParam);
	}
}
void* forEachXY(void* arr, int size, int count, int x, int y, CALLBACKXY pFunc){
	int i = 0;
	int j = 0;
	for(i = 0; i < y; i++){
		for(j = 0; j < x; j++){
			pFunc(arr + i * x *size + j * size, &j, &i);
		}
	}
}
void* forEachXyEx(void* arr, int size, int count, int x, int y, CALLBACKXYEX pFuncEx, void* pParam){
	int i = 0;
	int j = 0;
	for(i = 0; i < y; i++){
		for(j = 0; j < x; j++){
			pFuncEx(arr + i * x * size + j * size, &j, &i, pParam);
		}
	}
}
void getKB(float* pK, int* pB, int x, int y){
	*pK = 0 - *pK;
	*pB = y - *pK * x;
}
void goStraightLine(POINT* pPoint, float* pK, int* pB, int* pTurn){
		if(pPoint->x >= 40){
			*pTurn ^= 1;
			getKB(pK, pB, pPoint->x, pPoint->y);
		}
		if(pPoint->x <= 0){
			*pTurn ^= 1;
			getKB(pK, pB, pPoint->x, pPoint->y);
		}
		if(pPoint->y >= 30){
			getKB(pK, pB, pPoint->x, pPoint->y);
		}
		if(pPoint->y <= 0){
			getKB(pK, pB, pPoint->x, pPoint->y);
		}
		if(!*pTurn)
			pPoint->x++;
		else
			pPoint->x--;
		pPoint->y = (*pK * pPoint->x + *pB) - (int)(*pK * pPoint->x + *pB) >= 0.5 ? (int)(*pK * pPoint->x + *pB) + 1 : (int)(*pK * pPoint->x + *pB);
}
