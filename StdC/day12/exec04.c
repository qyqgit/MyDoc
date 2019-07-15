#include <stdio.h>
int main(){
	int size = 0;
	int arr[5][5] = {0};
	FILE* p_file = fopen("tmp.bin", "rb");
	if(p_file){
		size = fread(arr, sizeof(int), 25, p_file);
		printf("size:%d\n", size);
		fclose(p_file);
		p_file = NULL;
	}
	for(int i = 4; i >= 0; i--){
		for(int j = 0; j < 5; j++){
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
