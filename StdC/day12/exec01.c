#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y;
} pt_t;
typedef struct {
	pt_t pt1;
	pt_t pt2;
} rect_t;
pt_t* mid_pt(const rect_t *p_rect){
	pt_t* p_mid = (pt_t*)malloc(sizeof(pt_t));
	if(p_mid){
		p_mid->x = (p_rect->pt1.x + p_rect->pt2.x) / 2;
		p_mid->y = (p_rect->pt1.y + p_rect->pt2.y) / 2;
	}
	return p_mid;
	
}
int main (){
	rect_t rect = {0};
	pt_t* p_mid = NULL;
	scanf("%d%d%d%d", &rect.pt1.x, &rect.pt1.y, &rect.pt2.x, &rect.pt2.y);
	p_mid = mid_pt(&rect);
	if(p_mid){
		printf("%d %d\n", p_mid->x, p_mid->y);
	}
	free(p_mid);
	p_mid = NULL;
	return 0;
}
