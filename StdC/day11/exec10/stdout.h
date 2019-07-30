#ifndef __STDOUT_H__
#define __STDOUT_H__
#include <stdio.h>
#define WIDTH	40
#define HEIGHT	30
extern char gScreenBuff[HEIGHT][WIDTH];
void initScreen();
void showScreen();
void screenShot();
void showImage();
#endif
