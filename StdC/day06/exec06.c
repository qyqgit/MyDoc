#include<stdio.h>
long long fun(int index){
    if(index <= 1){
        return 1;
    }
    return fun(index - 1) + fun(index - 2);
}
int main(){
    printf("%lld\n", fun(60));
}

