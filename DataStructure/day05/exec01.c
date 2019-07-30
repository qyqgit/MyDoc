#include <stdio.h>
void bubble_sort(int *p_val, int size){
	int num = 0;
	int num1 = 0;
	int tmp = 0;
	for(num = size - 1; num >= 1; num--){
		for(num1 = 1; num1 <= num; num1++){
			//每次循环把下标为num1-1和num1的两个存贮区内容做顺序调整
			if(*(p_val + num1 - 1) > *(p_val + num1)){//如果前面大后面小则交换
				tmp = *(p_val + num1 - 1);
				*(p_val + num1 -1) = *(p_val + num1);
				*(p_val + num1) = tmp;
				
			}
		}
	}
	
}
void choice_sort(int *p_val, int size){
	int num = 0;
	int num1 = 0;
	int tmp = 0;
	for(num = size - 1; num >= 1; num--){
		//循环变量代表选定位置前每个位置的下标
		for(num1 = 0; num1 <= num-1; num1++){
			if(*(p_val + num1) > *(p_val + num)){
				tmp = *(p_val + num1);
				*(p_val + num1) = *(p_val + num);
				*(p_val + num) = tmp;
			}
		}


	}
}

void insert_sort(int *p_val, int size){
	int num = 0;
	int num1 = 0;
	int tmp = 0;
	for(num = 1; num <= size -1; num++){
		for(num1 = num -1; num1 >= 0; num1--){
			//循环变量代表要插入位置的下标
			if(*(p_val + num1) > *(p_val + num1 + 1)){
				//前面的数字大，后面的数字小时插入
					tmp = *(p_val + num1);
					*(p_val + num1) = *(p_val + num1 + 1);
					*(p_val + num1 + 1) = tmp;

			}else {
				break;
			}

		}
	}

}
void quick_sort(int *p_val, int size){
	int base = *p_val;//把最前面的数字作为选定数字记录下来
	int *p_head =p_val;//指向两个要进行顺序
	int *p_tail = p_val + size -1;//指向两个进行顺序调整的存储区里后面那个
	int tmp = 0;
	if(size <= 1){
		//数字里只有一个存储区
		return;
	}
	while(p_head < p_tail){//如果两个指针没有重合就应该继续
		//每次循环把选定数字和另外一个数字进行顺序调整
		if(*p_head > *p_tail){
			//前面的大就交换
			tmp = *p_head;
			*p_head = *p_tail;
			*p_tail = tmp;
		}
		//排除其中非选定数字
		if(base == *p_head){
			//如果选定数字在前面就排除后面的数字
			p_tail--;
		}else {
			//如果选定数字在后面就排除前面的数字
			p_head++;
		}

	}
	//循环结束后两个指针重合，他们都指向选定数字所在的存储区
	//递归调用quick_sort函数对左半边数字递归
	quick_sort(p_val, p_head - p_val);
	//递归调用quick_sort函数对右半便数字进行排序
	quick_sort(p_head + 1, size - (p_head - p_val) - 1);

}
int main(){
	int arr[] = {50, 30, 80, 20, 60, 10, 40, 70};
	//bubble_sort(arr, 8);
	//choice_sort(arr, 8);
	//insert_sort(arr, 8);
	quick_sort(arr, 8);
	for(int i = 0; i <= 7; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}
