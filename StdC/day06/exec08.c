#include<stdio.h>
static int a = 200;
int fun(){
    static int a = 100;
}
int main(){
    printf("%d\n", a);

}
