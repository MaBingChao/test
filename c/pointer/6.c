#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_cout(char *str, const char *zstr, int cont)
{
	int tmp_cont = cont;	
	int but[tmp_cont];
	char *tmp = str;
	char *tmp1 = str;
	char *tmp2 = NULL;
	int i;

	for(i=0;i<tmp_cont;i++)
	{
		tmp = strstr(tmp,zstr);
		if(tmp == NULL)
			break;
		but[i]=strlen(tmp1)-strlen(tmp)+1;	// '\0'
		tmp = tmp+1;
		tmp1 = tmp;
		tmp2 = tmp;	
	}
	while(*tmp2++)
		but[i]++;
	but[i]++;

	return 0;
}

int cont_num(char *str, const char *zstr, int *cont)
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
	tmp_cont++;
	*cont = tmp_cont;	
}


int main(void)
{
	char *str="aa,bbbb,casdf,fasdfg,1234,c,dd,aa,cc,aa";
	char *zstr=",";
	int cont = 0;
	cont_num(str, zstr, &cont);
	
	str_cout(str, zstr, cont);
	
	
	return 0;
}
