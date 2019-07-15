#include <stdio.h>
int main(int argc, char* argv[]){
	if(argc < 3){
		return 0;
	}
	int size = 0;
	FILE* pFile1 = fopen(argv[1], "rb");
	FILE* pFile2 = fopen(argv[2], "wb");
	if(!(pFile1 && pFile2)){
		printf("open file fail.\n");
		if(pFile1){
			fclose(pFile1);
			pFile1 = NULL;
		}
		return 0;
	}
	char buff[1024 * 1024] = {0};
	//size = fread(buff, sizeof(char), 1024 * 1024, pFile1);
	//printf("%d\n", size);
	/*while(buff1[i] != EOF){
		size++;
	}*/
	while(1){
		size = fread(buff, sizeof(char), 100, pFile1);
		if(!size){
			break;
		}
		fwrite(buff, sizeof(char), size, pFile2);
	}
	fclose(pFile1);
	fclose(pFile2);
	pFile1 = NULL;
	pFile2 = NULL;
	return 0;
}
