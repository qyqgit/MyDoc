#include <stdio.h>
#include "tree.h"
void print_cb(int val){
	printf("%d ",val);
}
int main(){
	tree_t tr = {0};
	tree_init(&tr);
	tree_insert(&tr, 50);
	tree_insert(&tr, 25);
	tree_insert(&tr, 75);
	tree_insert(&tr, 13);
	tree_insert(&tr, 37);
	tree_insert(&tr, 67);
	tree_insert(&tr, 88);
	tree_insert(&tr, 7);
	printf("height:%d\n", tree_height(&tr));
	tree_remove(&tr, 25);
	printf("height:%d\n", tree_height(&tr));
	//tree_remove(&tr, 88);
	tree_miter(&tr, print_cb);
	printf("\n");

	printf("count:%d\n", tree_size(&tr));
	tree_deinit(&tr);
	return 0;
}