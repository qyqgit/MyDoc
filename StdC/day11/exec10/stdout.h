#ifndef __STDOUT_H__
#define __STDOUT_H__
#include <stdio.h>
#define WIDTH	40
#define HEIGHT	30
char gScreenBuff[HEIGHT][WIDTH];
void initScreen();
void showScreen();
void showLine(char* lineBuff);
void showPixel(char* pChar);
void screenShot();
void screenShotLine(char* lineBuff, FILE* pFile);
void screenShotWriteFile(char* pChar, FILE* pFile);
#endif
