#include <stdio.h>
#include <stdlib.h>

int a[10] = {1,1,0,3,3,2,2,2,0,1};

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
	//get_number();
	print();
	
	quick_sort(0,9);
	print();
	
	return 0;
}