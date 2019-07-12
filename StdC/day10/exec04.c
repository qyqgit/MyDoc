#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct point{
	int x;
	int y;
} POINT;
typedef struct circle{
	POINT 	point;
	int	r;
} CIRCLE;
CIRCLE* get_bigger(const CIRCLE* circ1, const CIRCLE* circ2){
	return (CIRCLE*)(circ1->r > circ2->r ? circ1 : circ2);

}
void get_circle(CIRCLE* circ){
	scanf("%d %d %d", &circ->point.x, &circ->point.y, &circ->r);
}
void print_circle(const CIRCLE *circ){
	for(int y = 0; y < 30; y++){
		for(int x = 0; x < 40; x++){
			if((x - circ->point.x) * (x - circ->point.x) + (y - circ->point.y) * (y - circ->point.y) < circ->r * circ->r)
				printf("0 ");
			else
				printf(". ");
		}
		printf("\n");
	}
}
void print_two_circle(const CIRCLE *circ, const CIRCLE *circ2){
	for(int y = 0; y < 30; y++){
		for(int x = 0; x < 40; x++){
			if((x - circ->point.x) * (x - circ->point.x) + (y - circ->point.y) * (y - circ->point.y) < circ->r * circ->r || (x - circ2->point.x) * (x - circ2->point.x) + (y - circ2->point.y) * (y - circ2->point.y) < circ2->r * circ2->r)
				printf("0 ");
			else
				printf(". ");
		}
		printf("\n");
	}
}
void get_kb(float *k, int *b, int x, int y){
	*k = 0 - *k;
	*b = y - (*k) * x; 
}
int main(){
	CIRCLE circ1;
	//CIRCLE circ2;
	
	get_circle(&circ1);
	//get_circle(&circ2);
	
	//print_circle(&circ1);
	//print_circle(&circ2);

	//print_two_circle(&circ1, &circ2);
	float k = (float)circ1.point.y / (float)circ1.point.x;
	int b = 0;
	int turn_x = 1;
	while(1){
		system("clear");
		print_circle(&circ1);
		if(circ1.point.x >= 40){
			turn_x ^= 1;
			get_kb(&k, &b, circ1.point.x, circ1.point.y);
			printf("turn_x\n");
		}
		if(circ1.point.x <= 0){
			turn_x ^= 1;
			get_kb(&k, &b, circ1.point.x, circ1.point.y);
			printf("turn_x\n");
		}
		if(circ1.point.y >= 30){
			get_kb(&k, &b, circ1.point.x, circ1.point.y);
			printf("turn\n");
		}
		if(circ1.point.y <= 0){
			get_kb(&k, &b, circ1.point.x, circ1.point.y);
			printf("turn\n");
		}
		if(turn_x)
			circ1.point.x++;
		else
			circ1.point.x--;
		circ1.point.y = (int)(k * circ1.point.x + b);
		printf("K=%f\n", k);
		printf("B=%d\n", b);
		printf("X=%d Y=%d\n", circ1.point.x, circ1.point.y);
		sleep(1);
	}
}
