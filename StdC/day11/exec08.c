#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y;
} point_t;
point_t *get_point(void){
	static point_t pt = {0};
	scanf("%d %d", &pt.x, &pt.y);
}
point_t *get_point1(void){
	point_t* p_point =  (point_t*)malloc(sizeof(point_t));
	if(!p_point)
		return NULL;
	scanf("%d %d", &p_point->x, &p_point->y);
	return p_point;

}
int main(){
	point_t *p_point = get_point1();
	if(!p_point)
		return 0;
	printf("%d %d\n", p_point->x, p_point->y);
	free(p_point);
	return 0;
}
