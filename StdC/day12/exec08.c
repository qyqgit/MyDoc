#include <stdio.h>
int main(){
	char ch = 0;
	FILE* p_file = fopen("tmp.txt", "rb");
	if(!p_file){
		return 0;
	}
	fseek(p_file, 2, SEEK_SET);
	fseek(p_file, 4, SEEK_CUR);
	fseek(p_file, -4, SEEK_END);
	long index = ftell(p_file);
	printf("index:%ld\n", index);
	fread(&ch, sizeof(char), 1, p_file);
	printf("%c\n", ch);
	index = ftell(p_file);
	printf("index:%ld\n", index);
	//
	rewind(p_file);
	//
	fread(&ch, sizeof(char), 1, p_file);
	printf("%c\n", ch);
	index = ftell(p_file);
	printf("index:%ld\n", index);
	fread(&ch, sizeof(char), 1, p_file);
	printf("%c\n", ch);
	fclose(p_file);
	p_file = NULL;
	return 0;
}
