#include <stdio.h>
int main(){
	int size = 0;
	FILE* p_file = fopen("tmp.bin", "rb");
	/*if(p_file){
		fclose(p_file);
		p_file = NULL;
	}*/
	if(!p_file){
		return 0;
	}
	int arr[] = {1, 2, 3, 4, 5, 6};
	/*size = fwrite(arr, sizeof(int), 6, p_file);
	printf("size:%d\n", size);
	fclose(p_file);
	p_file = NULL;*/

	p_file = fopen("tmp.bin", "rb");
	size = fread(arr, sizeof(int), 6, p_file);
	printf("size:%d\n", size);
	for(int i = 0; i < 6; i++){
		printf("%d\n", arr[i]);
	}
	fclose(p_file);
	p_file = NULL;
	return 0;
}
