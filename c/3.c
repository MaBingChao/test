#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *str="aa,bbbb,cc,dd";
	char *zstr=",";
	
	char *tmp=str;
	
	int cont = 0;
	
	
	while(*tmp != '\0')
	{
		tmp = strstr(str,zstr);
		if(tmp == NULL)
			break;
		cont++;
		tmp = tmp+1;
	}

	printf("cont is %d\n", cont);
	return 0;
}
