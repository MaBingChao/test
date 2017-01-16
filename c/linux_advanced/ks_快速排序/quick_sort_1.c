#include <stdio.h>

int a[10] = {1,6,5,2,3,9,8,4,0,7};

int quick_sort(int left, int right)
{
	
	if(left > right)
	{
		return 0;
	}
	int i,j;
	int base, tmp;
	
	i = left;
	j = right;
	base = a[i];
	while(i < j)
	{
		while((a[j] > base) && (i < j))
			j--;
		
		while((a[i] < base) && (i < j))
			i++;
		
		if(i < j)
		{
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}
	
	quick_sort(left, i-1);
	quick_sort(i+1, right);
	
	return 0;
	
}


int main(void)
{
	quick_sort(0,9);
	int i;
	
	for(i = 0; i <10; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	
	return 0;
}