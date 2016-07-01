#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_cout(char *str, const char *zstr, int *cont)
{
	int tmp_cont = 0;
	char *tmp=str;

	while(*tmp != '\0')
	{
		tmp = strstr(tmp,zstr);
		if(tmp == NULL)
			break;
		tmp = tmp+1;
		tmp_cont++;
	}
	*cont = tmp_cont;
	return 0;
}

int main(void)
{
	char *str="aa,bbbaab,cc,dd,aa,abaa";
	char *zstr=",";
	int cont = 0;
	int ret = 0;
	ret = str_cout(str, zstr, &cont);
	printf("cont is %d\n", cont);
	return 0;
}
