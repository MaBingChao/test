#include <stdio.h>
#include <stdlib.h>
int main(void)
{	
	int a[10] = {1,2,3};
	int b;
//	int *d = &b;
	int *d = NULL;
//	d = malloc(sizeof(int));
	d = a;		 //编译会报错	
	*d = a[1];	 //执行会出现段错误，指针没有初始化（野指针）

	printf("%d\n", *d);

	return 0;
}
