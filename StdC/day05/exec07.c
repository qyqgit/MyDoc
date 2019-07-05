#include<stdio.h>
#define N 10
int main(){
    int arr[N][N] = {0};
    int val = 1;
    float loop2 = N - 0.5;
    int times = 0;
    int i = 0;
    int j = 0;
	for(int ii = 0; ii < N - 1; ii++){
		j++;
		arr[i][j] = val;
		val++;
	}
    for(int loop = 1; loop <= 2 * N - 2; loop++){

        times++;
        //printf("%f\n", loop2);
        for(int ii = 0; ii < (int)loop2; ii++){
            if(times %  4 == 0){
                j++;
            }
            if(times % 4 == 1){
                i++;
            }
            if(times % 4 == 2){
                j--;
            }
            if(times % 4 == 3){
                i--;
            }
            arr[i][j] = val;
            val++;
        }
    	loop2 -= 0.5;    
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%02d ", arr[i][j]);
        }
        printf("\n");
    }
	return 0;

}
