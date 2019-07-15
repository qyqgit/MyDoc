#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "stdout.h"

char gScreenBuff[HEIGHT][WIDTH] = {0};
int screenShotIndex = 0;
void initScreen(){
	memset(gScreenBuff, '.', WIDTH * HEIGHT);
	//memset(screenBuff, '1', WIDTH);
	//memset(screenBuff + 1, '2', WIDTH);
	//memset(screenBuff + 2, '3', WIDTH);
	//memset(screenBuff + HEIGHT - 1, '0', WIDTH);
}
void showScreen(){
	system("clear");
	forEach(gScreenBuff, sizeof(gScreenBuff[0][0]) * WIDTH, HEIGHT, (CALLBACK)showLine);
}
void showLine(char* lineBuff){
	forEach(lineBuff, sizeof(gScreenBuff[0][0]), WIDTH, (CALLBACK)showPixel);
	printf("\n");
}
void showPixel(char* pChar){
	printf("%c", *pChar);
}
void screenShot(){
	char tmp[100] = {0};
	sprintf(tmp, "%04d.txt", screenShotIndex++);
	FILE* pFile = fopen(tmp, "w");
	if(pFile){
		forEachEx(gScreenBuff, sizeof(gScreenBuff[0][0]) * WIDTH, HEIGHT, (CALLBACKEX)screenShotLine, pFile);
		fclose(pFile);
		pFile = NULL;
	}
}
void screenShotLine(char* lineBuff, FILE* pFile){
	forEachEx(lineBuff, sizeof(gScreenBuff[0][0]), WIDTH, (CALLBACKEX)screenShotWriteFile, pFile);
	screenShotWriteFile("\n", pFile);
}
void screenShotWriteFile(char* pChar, FILE* pFile){
	fwrite(pChar, sizeof(gScreenBuff[0][0]), 1, pFile);
}
