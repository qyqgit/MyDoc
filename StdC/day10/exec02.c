#include <stdio.h>
typedef struct point{
	int x;
	int y;
} POINT;
typedef struct rect{
	POINT point;
	int height;
	int width;
} RECT;
void print_rect(const RECT *rect){
	for(int y = 0; y < 30; y++){
		for(int x = 0; x < 40; x++){
			if(x >= rect->point.x && x < rect->point.x + rect->width && y >= rect->point.y && y < rect->point.y + rect->height)
				printf("0 ");
			else
				printf(". ");
		}
		printf("\n");
	}
}
void get_rect(RECT *rect){
	scanf("%d %d %d %d", &rect->point.x, &rect->point.y, &rect->width, &rect->height);
}
int get_area(const RECT *rect){
	return rect->width * rect->height;
}
void get_rect_center(const RECT *rect, POINT *point){
	point->x = rect->point.x + rect->width / 2;
	point->y = rect->point.y + rect->height / 2;
}
int main(){
	RECT rect;
	scanf("%d %d %d %d", &rect.point.x, &rect.point.y, &rect.width, &rect.height);
	printf("s=%d\n", rect.height *  rect.width);

	POINT point;
	point.x = rect.point.x + rect.width / 2;
	point.y = rect.point.y + rect.height / 2;
	printf("mid_x=%d mid_y=%d\n", point.x, point.y);
	print_rect(&rect);
	get_rect(&rect);
	print_rect(&rect);
	printf("s=%d\n", get_area(&rect));
	get_rect_center(&rect, &point);
	printf("mid_x=%d mid_y=%d\n", point.x, point.y);
}
