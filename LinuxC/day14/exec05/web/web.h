#ifndef WEB_H_
#define WEB_H_
typedef struct{
    char method[32];
    char path[128];
    char proto[32];
}req_t;

typedef struct{
    int code;
    char *f_type;
}res_t;


#endif
