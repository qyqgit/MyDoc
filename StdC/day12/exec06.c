#include <stdio.h>
int main(){
	int val = 0;
	int num = 0;
	FILE* p_file = fopen("tmp.txt", "r");
	if(p_file){
	for (num = 0; num < 5; num++){
		//scanf("%d", &val);
		fscanf(p_file, "%d", &val);
		printf("%d\n", val);
	}
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
