#include<stdio.h>
#include<math.h>
int main(){
    int arr[5] = {0};
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    printf("%d\n", sizeof(arr));
    printf("******************\n");
    int a = 0;
    scanf("%d", &a);
    for(int i = 4; i >= 0; i--){
        arr[i] = a / pow(10, i );
        a = a - arr[i] * pow(10, i );
        /*
         * arr[i] = a % 10;
         * a /= 10;
         * if(!a){
         *      break;
         * }
         *
         * */
    }
    for(int i = 4; i >=0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
