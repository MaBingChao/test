#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * int_char(int number);

int main(void)
{	
	char *str = NULL;

	str = malloc(sizeof(char *));

	str = int_char(123456);
	printf("str is %s..\n", str);

	return 0;
}

char * int_char(int number)
{
	char *pstr = NULL;
	char *qstr = NULL;
	char *sstr = NULL;
	int count=0;
	int i;

	pstr = malloc(sizeof(char *));
	qstr = malloc(sizeof(char *));

	if(number > 0)
	{
		while(number)
		{
			count++;
			*pstr++ = number%10 + '0';
			number /= 10;
		}
		--pstr;
		sstr = qstr = pstr;
		for(i = 0; i < count; i++)
		{
			*qstr++ = *pstr--;
		}
		*qstr = '\0';
		printf("qstr is %s..\n", sstr);
		
	}
	return sstr;
}
