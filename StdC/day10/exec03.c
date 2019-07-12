#include <stdio.h>
int main(){
	struct tmp0 {
		char	a[2];
		int 	b;	
	};
	struct tmp1 {
		int 	b;	
		char	a[2];
	};
	struct tmp2 {
		char 	a;
		int	b;
		char	c;
	};
	printf("%d %d %d\n", sizeof(struct tmp0), sizeof(struct tmp1), sizeof(struct tmp2));
}
