#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
	if(argc < 3)
		return 0;
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("head:%d foot:%d\n", a, b);
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= a; j++){
			if(i + j == a && i * 4 + j * 2 == b)
				printf("rabbit:%d chiken:%d",i , j);
		}
	}
	printf("\n");
}
