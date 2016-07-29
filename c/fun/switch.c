#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int num;
	
	scanf("%d", &num);
	
	switch(num)
	{
		case 1 :
			printf("1111111111111\n");
		case 2 :
			printf("2222222222222\n");
		case 3 :
			printf("3333333333333\n");
		case 4 :
			printf("4444444444444\n");
		
		default :
			printf("0000000000000\n");
	}

		
	return 0;
}