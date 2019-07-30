#include <stdio.h>
//#include <errno.h>
//#include <string.h>
#define E_MSG(STR,VAL) do{perror(STR);return(VAL);}while(0)
int main(int argc, char* argv[]){
	FILE *fp = fopen(argv[1],"r");
/*	if(fp == NULL){
#if 0
		printf("fopen failed:%d_%s\n", errno, strerror(errno));
		return -1;
#endif
		perror("fopen123");
		return -1;
	}*/
	if(fp == NULL)E_MSG("fopen321", -1);
	printf("open file success.\n");
	fclose(fp);
	return 0;
}
