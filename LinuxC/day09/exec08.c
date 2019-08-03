#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
extern char** environ;
int isfile(char *path){
	struct stat buf;
	int status = stat(path, &buf);
	if(status == -1){
		return 0;
	}
	if(S_ISREG(buf.st_mode))
		return 1;
	else
		return 0;
}
char *getpathmall(char *filepath){
	char *path = getenv("PATH");
	char *p = path;
	char tmp[100];
	while(strstr(p ,":")){
		int n = strstr(p, ":") - p;
		strncpy(tmp, p, n);
		tmp[n] = '\0';
		p = p + n + 1;
		strcat(strcat(tmp, "/"), filepath);
		if(isfile(tmp)){
			//printf("elf:%s\n", tmp);
			char *result = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
			strncpy(result, tmp, strlen(tmp));
			result[strlen(tmp)] = '\0';
			return result;
		}
	}
	strcpy(tmp, p);
	strcat(strcat(tmp, "/"), filepath);
	if(isfile(tmp)){
		//printf("elf:%s\n", tmp);
		char *result = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strncpy(result, tmp, strlen(tmp));
		result[strlen(tmp)] = '\0';
		return result;
	}
	return NULL;
}
void formatstrmalloc(char *inputstr, int *argcc, void *argvv){
	int argc = 0;
	char *p = inputstr;
	char *argvs[15];
	char tmp[100];
	int i = 0;
	while(*p != '\0'){
		while(*p == ' ')p++;
		while(*p != ' ' && *p != '\0'){
			tmp[i] = *p;
			i++;
			p++;
		}
		tmp[i] = '\0';
		i = 0;
		argvs[argc] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
		strcpy(argvs[argc], tmp);
		argc++;
	}
	*argcc = argc;
	memcpy(argvv, argvs, sizeof(argvs));
}
void showenv(){
	int i = 0;
	while(environ[i]){
		printf("%s\n",environ[i]);
		i++;
	}
}
int main(int argc, char *argv[]){
	char	inputstr[255];
	int	quit = 0;
#if 10	
	do{
		fgets(inputstr, 200, stdin);
		if(!(strstr(inputstr, "quit") - inputstr))
			break;
		else{
			const char filename[100];
			strncpy((char*)filename, inputstr, strlen(inputstr) - 1);//remove '\n'
			((char*)filename)[strlen(inputstr) - 1] = '\0';
			
			pid_t pid = fork();
			if(pid == -1){
				perror("fork");
				exit(-1);
			}
			if(pid == 0){
				int argcc = 0;
				char *argvvss[15];
				char buf[15][100];
				char *argvv[15];
				formatstrmalloc((char*)filename, &argcc, argvvss);
				int num = 0;
				while(argcc){
					strcpy(buf[num], argvvss[num]);
					free(argvvss[num]);
					argvv[num] = buf[num];
					argcc--;
					num++;
				}
				argvv[num++] = '\0';//Both argv and envp must be terminated by a null pointer.
				char *p = getpathmall(buf[0]);
				if(p == NULL){
					printf("not found.\n");
					exit(-1);
				}
				strcpy(inputstr, p);
				free(p);
				execve(inputstr, argvv, environ);
				perror("execve");
				exit(-1);
			} else {
				wait(NULL);
				//printf("parent end\n");
			}
		}
		inputstr[0] = '\0';
	}while(!quit);
#endif	
	return 0;
}
