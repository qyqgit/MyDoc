#include<stdio.h>
#include<math.h>
int a[32] = {0};
int len = 1;
void toBin(int i){
        int index = 0;
        while(i){
            a[index] = i % 2;
            i = i / 2;
            index++;
            len++;
        }
        index--;
        while(index >= 0){
            printf("%d",a[index]);
            index--;
        }
        printf("\n");
}
void toRel(){
    int index = 0;
    //printf("%d\n",len);
    while(index < len){
        a[index] == 1 ? (a[index] = 0) :( a[index] = 1);
        index++;
    }
    index--;
    while(index >= 0){
        //printf("%d",a[index]);
        index--;
    }
    printf("\n");
}
int addOne(){
    int x = 0;
    while(len >= 0){
        x = pow(2,len) * a[len] + x;
        len--;
    }
    x++;
    return x;
}
int main(){
    int i = 0;
    scanf("%d",&i);
    if(i >= 0){
        toBin(i);         
    }else{
        i = -i;
        toBin(i);
        toRel();
        while(len - 32 <0){
            printf("1");
            len++;
        }
        toBin(addOne());
    }


}
