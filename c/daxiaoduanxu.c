#include <stdio.h>

int main(void)
{
	char a[18];
	char b[0];
	
	int c[18];
	int d[0];
	
	printf("a = %p\nb = %p\na - b = %p\n", a, b, a-b);
	printf("a = %d\nb = %d\na - b = %d\n", a, b, a-b);
	
	printf("c = %p\nd = %p\nc - d = %p\n", c, d, c-d);
	printf("c = %d\nd = %d\nc - d = %d\n", c, d, c-d);
	
	return 0;
}