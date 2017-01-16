#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	
	// C中表达式返回的是变量的值10, 要改变，可以用指针去间接修改
	// (a < b ? a: b) = 30;
	*(a < b ? &a : &b) = 30;
	printf("a = %d\n", a);
	
	return 0;
}