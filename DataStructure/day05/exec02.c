#include <stdio.h>
int *half_search(const int *p_val, int size, int val){
	const int *p_head = p_val;//指针p_head指向范围里第一个存储区
	const int *p_tail = p_val + size - 1;//指针p_tail指向查找范围里最后一个存储区
	const int  *p_mid = NULL;//指针p_mid指向查找范围里中间位置的存储区
	while(p_head <= p_tail){//两个指针没有交错则继续查询
		//没循环一次排除一般的存储区
		p_mid = p_head + (p_tail - p_head + 1) / 2;
		if(*p_mid == val){
			//中心点位置存贮区内容为要找的数
			return (int*)p_mid;
		}else if(*p_mid > val){
			//中心点位置存储区内容比要找的数字大排除右半边所有数字
			p_tail = p_mid - 1;

		}else{
			//中心点位置存储区的内容比要查找的数字小就可以排除左半边的所有数字
			p_head = p_mid + 1;
		}
	}
	return NULL;
	
}
int main(){
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int *p_val = half_search(arr, 10, 20);
	if(p_val){
		printf("found:%d\n", *p_val);
	}else {
		printf("not found.\n");
	}
	return 0;
}
