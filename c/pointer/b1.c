#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{	
	char *name = "         asdfgadfsdfsa                 ";
	char *top = name;
	char *end = NULL;
	char newname[40];
	
	while(1)
	{
		if(*top != ' ')
		{
			break;
		}
		else
		{
			top++;
		}
	}

	end = top;
	while(1)
	{
		if(*end == ' ' || *end == '\0')
		{
			break;
		}
		else
		{
			end++;
		}
	}
	
	memcpy(newname, top, end - top);

	printf("len is %d\n",end - top);
	printf("name is %s\n",name);
	printf("newname is %s\n",newname);

	return 0;
}
