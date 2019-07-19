#include <stdio.h>
#include "link.h"
int main(){
	int val = 0, size = 0, num = 0;
	link_t lnk = {0};
	link_init(&lnk);
	link_add_head(&lnk, 50);
	link_add_head(&lnk, 30);
	link_append(&lnk, 80);
	link_append(&lnk, 100);
	link_insert(&lnk, 60);
	link_insert(&lnk, 40);
	link_insert(&lnk, 10);
	link_insert(&lnk, 20);
	link_insert(&lnk, 90);
	link_insert(&lnk, 70);
	link_remove_head(&lnk);
	link_remove_tail(&lnk);
	link_remove(&lnk, 80);
	link_get_head(&lnk, &val);
	printf("head:%d\n", val);
	link_get_tail(&lnk, &val);
	printf("tail:%d\n", val);
	size = link_size(&lnk);
	for(num = 0; num <= size - 1; num++){
		link_get(&lnk, num, &val);
		printf("%d ",val);	
	}
	printf("\n");
	link_deinit(&lnk);
	return 0;
}
