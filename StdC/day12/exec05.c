#include <stdio.h>
int main(){
	int arr[] = {49, 999, 33 ,333, 4};
	int num = 0;
	FILE* p_file = fopen("tmp.txt", "w");
	if(p_file){
		for(num = 0; num <= 4; num++){
			//printf("%d ", arr[num]);
			fprintf(p_file, "%d ", arr[num]);
		}
		fprintf(p_file, "\n");
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}
