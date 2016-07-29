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
	char *cstr = NULL;
	char tmp;
	int count=0;
	int i;

	pstr = malloc(sizeof(char *));
	cstr = malloc(sizeof(char *));
	qstr = cstr;

	if(number > 0)
	{
		while(number)
		{
			count++;
			*pstr++ = number%10 + '0';
			number /= 10;
		}
		--pstr;
		for(i = 0; i < count; i++)
		{
			*cstr++ = *pstr--;
		}
		*cstr = '\0';
		printf("qstr is %s..\n", qstr);
		
	}
	return qstr;
}
