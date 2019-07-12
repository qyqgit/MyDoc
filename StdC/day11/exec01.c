#include <stdio.h>
typedef union{
	unsigned char c;
	int val;
	float fval;
	double dval;
} TMP;
int main(){
	enum season{SPRING, SUMMER = 5, AUTUMN, WINTER};
	typedef enum season SS;
	SS ss1;
	printf("AUTUMN:%d\n", AUTUMN);

	TMP tmp;
	printf("%d\n", sizeof(tmp));
	tmp.c = 'a';
	printf("%d\n", sizeof(tmp));
	printf("%p\n", &tmp.c);
	printf("%p\n", &tmp.val);
	printf("%d\n", tmp.c);
	tmp.val = 2;
	printf("%d\n", tmp.c);
	return 0;
}
