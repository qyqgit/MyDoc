#include <stdio.h>
#include <stdlib.h>
typedef struct _POINT{
	int x;
	int y;
} POINT;
typedef struct _RECT{
	POINT point;
	int width;
	int height;
} RECT;
RECT *get_rect(){
	RECT *p_rect = (RECT*)malloc(sizeof(RECT));
	if (!p_rect)
		return NULL;
	scanf("%d %d %d %d", &p_rect->point.x, &p_rect->point.y, &p_rect->width, &p_rect->height);
	return p_rect;
}
POINT *get_rect_center(const RECT *rect){
	POINT *p_point = (POINT*)malloc(sizeof(POINT));
	if(!p_point)
		return NULL;
	p_point->x = rect->point.x + rect->width / 2;
	p_point->y = rect->point.y + rect->height / 2;
	return p_point;
	
}
int main(){
	RECT* p_rect = get_rect();
	if(!p_rect)
		return 0;
	printf("%d %d %d %d\n", p_rect->point.x, p_rect->point.y, p_rect->width, p_rect->height);

	POINT* p_point = get_rect_center(p_rect);
	if(!p_point)
		return 0;
	printf("%d %d\n", p_point->x, p_point->y);

	free(p_point);
	free(p_rect);
	return 0;
}
