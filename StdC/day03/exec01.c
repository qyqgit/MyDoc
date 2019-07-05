#include<stdio.h>
int main(){
    int gender = 0;
    int weight = 0;
    int height = 0;
    scanf("%d",&gender);
    scanf("%d",&height);
    scanf("%d",&weight);
    printf("%d\n",gender ? (height - weight < 105 ? 1 : 0):(height - weight < 110 ? 1 : 0));
    printf("%d\n",(gender && (height - weight < 105))||(!gender && (height - weight < 110)));
}
