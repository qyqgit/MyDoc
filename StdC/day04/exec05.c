#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int a = 0;
    int b = 0;
    srand(time(0));
    a = rand() % 100;
    scanf("%d", &b);
    while(1){
        if(b > a){
            printf("大了\n");
        }
        else if(b < a){
            printf("小了\n");
        }
        else{
            printf("对了\n");
            break;
        } 
        scanf("%d", &b);
    }
}
