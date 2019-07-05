#include<stdio.h>
int main(){
    int idNum[18] = {0};
    int seed[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char result[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int sum = 0;
    int index = 0;
    long long id = 0;

    scanf("%lld", &id);
    printf("%lld\n",id);

    for(int i = 17; i >= 0; i--){
        idNum[i] = id % 10;
        id /= 10;
    }
    for(int i = 0; i < 17; i++){
        sum = sum + idNum[i] * seed[i];
    }
    index = sum % 11;
    printf("%c\n", result[index]);

}
