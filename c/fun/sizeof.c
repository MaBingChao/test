#include<stdio.h>

int main(void)
{
	int arr[]={1,2,3,4,5};
	int d = -1;
	int x;	

	/* sizeof返回的是一个unsigned int
	 * 不同类型之间运算要转换类型，将b转换成unsigned int，-1转换成int是一个很大的数
	 */
	if(sizeof(arr)/sizeof(arr[0]) > d)
	{
		x = arr[0];
		printf(" x = %d \n", x);
	}
	else
	{
		printf("error!!\n");
	}
	
	return 0;
}
