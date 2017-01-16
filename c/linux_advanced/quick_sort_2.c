#include <stdio.h>
#include <stdlib.h>

int a[10] = {0};
//10      19      8       15      1       18      4       17      5       7

/*
第一次 
a[i]=a[j]
i=0 j=9  a[0]=a[9]
右到左 第一个小于key的数放到第一个元素上a[i],第一个的值被覆盖
7-      19      8       15      1       18      4       17      5       7-
a[j]=a[i]
i=1 j=9 a[9]=a[1]
左到右 将第一个大于key的数放到上面的a[j]位置上,此时a[i]的值和a[j]的值一样
7      19-      8       15      1       18      4       17      5       19-
第二次
i=1 j=8 a[1]=a[8]
7      5-      8       15      1       18      4       17      5-       19
i=3 j=8 a[8]=a[3]
7      5      8       15-      1       18      4       17      15-       19
第三次
i=3 j=6 a[3]=a[6]
7      5      8       4-      1       18      4-       17      15       19
i=5 j=6 a[6]=a[5]
7      5      8       4      1       18-      18-       17      15       19
j--之后j=5 跳出循环此时i=5
将a[5]=18改成a[5]=10
第一次排序完成：
7      5      8       4      1       10-      18        17      15       19
循环完成10左边的都小，右边的都大
在递归的排序左边0-4 右边的 6-9
*/

int quick_sort(int left, int right)
{
	if(left > right)
		return ;
	
	int i,j,key;
	
	key = a[left];
	i = left;
	j = right;

	while(i < j)
	{
		while((i < j) && (a[j] > key))
			j--;
		a[i] = a[j];
		while((i < j) && (a[i] <= key))
			i++;
		a[j] = a[i];
	}
	a[i] = key;
	
	quick_sort(left, i-1);
	quick_sort(i+1, right);
	
	return 0;
	
}

void get_number(void)
{
	int i;
	srand(2);
	for(i = 0; i <10; i++)
	{
		a[i] = 0+rand()%20;
	}
	
}

void print(void)
{
	int i;
	for(i = 0; i <10; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

int main(void)
{
	get_number();
	print();
	
	quick_sort(0,9);
	print();
	
	return 0;
}