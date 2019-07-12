#include<stdio.h>
#define PI 		3.14f
#define C(r) 		(2 * PI * (r))
#define ABS(val)	(val >= 0 ? val : 0- val)	
#define NEG(val)	(0 - val)
#define SUB(a, b)	((a) - (b))
#define SQUARE(a)	((a)*(a))
int abs(int val){
	if(val >= 0){
		return val;
	}
	else {
		return 0 - val;
	}

}
void neg(int *p){
	*p = 0 - *p;
}
int main(){
	int r = 0;
	scanf("%d", &r);
	printf("C=%g\n", C(r));
	printf("ABS=%d\n", abs(r));
	printf("ABS=%d\n", ABS(r));
	neg(&r);
	printf("NEG=%d\n", r);
	printf("NEG=%d\n", NEG(r));
	int a = 0;
	int b = 0;
	scanf("%d%d",&a,&b);
	printf("2a-2b=%d\n", SUB(a + a, b + b));
	printf("2a*2a=%d\n", SQUARE(a + a));
	printf("%d\n",SUB(a + a, b + b) * SQUARE(a + a));
	//printf("SQUARE(++a)=%d\n", SQUARE(++a));
	printf("SQUARE(a++)=%d\n", SQUARE(a++));
}
