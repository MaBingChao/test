#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	
	// C�б��ʽ���ص��Ǳ�����ֵ10, Ҫ�ı䣬������ָ��ȥ����޸�
	// (a < b ? a: b) = 30;
	*(a < b ? &a : &b) = 30;
	printf("a = %d\n", a);
	
	return 0;
}