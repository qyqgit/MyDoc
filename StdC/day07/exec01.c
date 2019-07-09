#include<stdio.h>
#include<math.h>
int main(){
	long long sum = 0;
	long long tmp = 0;
	for(int i = 100; i <= 999; i++){
		tmp = i;
		for(int j = 1; j < 3; j++){
			sum = sum + pow(tmp % 10, 3);
			tmp /= 10;
		}
		sum = sum + pow(tmp, 3);
		//printf("%lld\n", sum);
		if(sum == i)
			printf("%d\n", i);
		sum = 0;
	}
	return 0;
}
