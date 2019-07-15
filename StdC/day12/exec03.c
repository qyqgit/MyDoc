#include <stdio.h>
int main(){
	int size = 0;
	int arr[][5] = {1, 1, 1, 1, 1,
			2, 2, 2, 2, 2,
			3, 3, 3, 3, 3,
			4, 4, 4, 4, 4,
			5, 5, 5, 5, 5};
	FILE* p_file = fopen("tmp.bin", "wb");
	if(p_file) {
		size = fwrite(arr, sizeof(int), 25, p_file);
		printf("size:%d\n", size);
		fclose(p_file);
		p_file = NULL;
	}

	return 0;
}
