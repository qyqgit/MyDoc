#include<stdio.h>
void print(int i){
    if(i < 1)
        return;
    print(i - 1);
    printf("%d\n",i);
}
int main(){
    print(100);
    return 0;
}
