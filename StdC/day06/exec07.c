#include<stdio.h>
long long fun(int index){
    static long long arr[70];//long long arr[50];
    if(index <= 1){
        return 1;
    }
    if(!arr[index - 2]){
        arr[index - 2] = fun(index -2);
    }
    if(!arr[index - 1]){
        arr[index - 1] = fun(index - 1);
    }
    return arr[index - 1] + arr[index - 2];
}
int main(){
    printf("%lld\n", fun(60));
}

