#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "emotor.h"
char key[15][100];
char val[15][100];
typedef struct{
    char method[32];
    char path[128];
    char proto[32];
}req_t;
void formatstr(char *post, int *argc){
	char *p;
	p = post;
	int argcc = 0;
	while(*p){

		if(*p != '\r' && *p != '\n'){
			int len = 0;
			while(*p != '=' && *p != '\0'){
				key[argcc][len] = *p;
				len++;
				p++;
			}
			key[argcc][len] = '\0';
			p++;//*p == NULL?
			int len2 = 0;
			while(*p != '&' && *p != '\0'){
				val[argcc][len2] = *p;
				len2++;
				p++;
			}
			val[argcc][len2] = '\0';
			argcc++;
		}
		if(*p)
			p++;
	}
	*argc = argcc;
	
}
int t_main(int connectfd){
	char request[1024];
	char response[1024];
	char hello[1024] = "HTTP/1.1 200 OK\r\n\
Content-Type: text/html;charset=UTF-8\r\n\
\r\n\
<html>\r\n\
<head>\r\n\
<title>Hello</title>\r\n\
</head>\r\n\
<body>\r\n\
<h1>Hello world!</h1>\r\n\
</body>\r\n\
</html>\r\n";
	char tarena[1024] = "HTTP/1.1 200 OK\r\n\
Content-Type: text/html;charset=UTF-8\r\n\
\r\n\
<html>\r\n\
<body>\r\n\
<h1>tarena!</h1>\r\n\
</body>\r\n\
</html>\r\n";
	char not_found[1024] = "HTTP/1.1 404 Not Found\r\n\
Content-Type: text/html;charset=UTF-8\r\n\
\r\n\
<html>\r\n\
<body>\r\n\
<h1>404 page not found!</h1>\r\n\
</body>\r\n\
</html>\r\n";
	char html[1024 * 100] = "HTTP/1.1 200 OK\r\n\
Date: Sat, 01 Jul 2017 14:51:26 GMT\r\n\
Server: Apache/2.4.7 (Ubuntu)\r\n\
Content-Language: zh-CN\r\n\
Vary: Accept-Encoding\r\n\
Keep-Alive: timeout=5, max=100\r\n\
Connection: Keep-Alive\r\n\
Content-Type: text/html;charset=UTF-8\r\n\
\r\n\
";
	char img_png[1024 * 100] = "HTTP/1.1 200 OK\r\n\
Date: Sat, 01 Jul 2017 14:51:26 GMT\r\n\
Server: Apache/2.4.7 (Ubuntu)\r\n\
Content-Language: zh-CN\r\n\
Vary: Accept-Encoding\r\n\
Keep-Alive: timeout=5, max=100\r\n\
Connection: Keep-Alive\r\n\
Content-Type: image/png\r\n\
\r\n\
";
	char url[128];
	char *url_start;
	char *url_end;
	while(1){
		req_t q;
		int readsize = read(connectfd, request, 1024);//get msg from client
		printf("%s\n",request);
		sscanf(request, "%s %s %s\r\n",q.method,q.path,q.proto);
		if(!strcmp("POST", q.method)){
			char post_list[1024];
			int argc = 0;
			int content_len = 0;
			sscanf(strstr(request, "Content-Length:"), "Content-Length: %d\r\n", &content_len);//strstr NULL?
			strncpy(post_list, strstr(request, "\r\n\r\n"), content_len + 4);
			post_list[content_len + 4] = '\0';
			formatstr(post_list, &argc);
			/*while(argc){
				write(connectfd, key[argc - 1], strlen(key[argc - 1]));//send to client
				write(connectfd, "\n", strlen("\n"));//send to client
				write(connectfd, val[argc - 1], strlen(val[argc - 1]));//send to client
				write(connectfd, "\n", strlen("\n"));//send to client
				argc--;
			}*/
			if(!strcmp("go",val[0])){
				int fd;
				fd = emotor_open();
				if (fd < 0) 
				    return -1;
				emotor_pwm_task();

				emotor_control_direction(CAR_FORWARD);
				emotor_control_speed(3000);
				sleep(5);
				emotor_close();
			}
			if(!strcmp("back",val[0])){
				int fd;
				fd = emotor_open();
				if (fd < 0) 
				    return -1;
				emotor_pwm_task();

				emotor_control_direction(CAR_BACK);
				emotor_control_speed(1000);
				sleep(5);
				emotor_close();
			}
			FILE* p_file = fopen("index.html", "r");
			if(p_file){
				printf("index.html\n");
				char tmp[100];
				while(1){
					int size = fread(tmp, sizeof(char), 99, p_file);
					tmp[size] = '\0';
					if(!size){
						break;
					}
					strcat(html, tmp);
				}
				fclose(p_file);
				p_file = NULL;
				write(connectfd, html, strlen(html));//send to client
				printf("serv connect break %d\n", strlen(html));	
			} else write(connectfd, hello, strlen(hello));//send to client
			break;
		}

		url_start = strstr(request, "/");
		url_end = strstr(request, " HTTP/1.1");
		strncpy(url, url_start, url_end - url_start );
		url[url_end - url_start] = '\0';
		printf("URL:%s\n", url);
		if(!strcmp("/hello.html", url)){
			printf("ok\n");
			write(connectfd, hello, strlen(hello));//send to client
			break;
		}
		if(!strcmp("/tarena.html", url)){
			printf("ok\n");
			write(connectfd, tarena, strlen(tarena));//send to client
			int fd;
			fd = emotor_open();
			if (fd < 0) 
			    return -1;
			emotor_pwm_task();

			emotor_control_direction(CAR_FORWARD);
			emotor_control_speed(1000);
			sleep(2);
	
			emotor_control_direction(CAR_BACK);
			emotor_control_speed(1000);
			sleep(2);
			emotor_close();
			break;
		}
		if(!strcmp("/", url)){
			FILE* p_file = fopen("index.html", "r");
			if(p_file){
				printf("index.html\n");
				char tmp[100];
				while(1){
					int size = fread(tmp, sizeof(char), 99, p_file);
					tmp[size] = '\0';
					if(!size){
						break;
					}
					strcat(html, tmp);
				}
				fclose(p_file);
				p_file = NULL;
				write(connectfd, html, strlen(html));//send to client
				printf("serv connect break %d\n", strlen(html));	
			} else write(connectfd, hello, strlen(hello));//send to client
			break;
		}
		char path[128] = ".";
		if(strrchr(url, '.') != NULL && (!strcmp(strrchr(url, '.'), ".png") || !strcmp(strrchr(url, '.'), ".PNG"))){
			FILE* p_file = fopen(strcat(path, url), "rb");
			if(p_file){
				printf("find png.\n");
				char tmp[100];
				char *img_start = img_png + strlen(img_png);
				while(1){
					int size = fread(tmp, sizeof(char), 99, p_file);
					tmp[size] = '\0';
					if(!size){
						break;
					}
					memcpy(img_start, tmp, size);
					img_start += size;
				}
				fclose(p_file);
				p_file = NULL;
				write(connectfd, img_png, img_start - img_png);//send to client
				printf("serv connect break %d\n", img_start - img_png);	
			}
			break;
		}
		FILE* p_file = fopen(strcat(path, url), "r");
		if(p_file){
			printf("find html.\n");
			char tmp[100];
			while(1){
				int size = fread(tmp, sizeof(char), 99, p_file);
				tmp[size] = '\0';
				if(!size){
					break;
				}
				strcat(html, tmp);
			}
			fclose(p_file);
			p_file = NULL;
			write(connectfd, html, strlen(html));//send to client
			printf("serv connect break %d\n", strlen(html));
			break;
		}
		printf("404\n");
		write(connectfd, not_found, strlen(not_found));//send to client
		break;
	
	}
	return 0;

}
