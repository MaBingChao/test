#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int str_cout(char *str, const char *zstr, int cont)
{	
	int but[tmp_cont];
	tmp = tmp1 = str;
	
	for(i=0;i<tmp_cont;i++)
	{
		tmp = strstr(tmp,zstr);
		if(tmp == NULL)
			break;
		but[i]=strlen(tmp1)-strlen(tmp);
		tmp = tmp+1;
		tmp2 = tmp1 = tmp;
	}
	but[i] = 0;
	while(*tmp2++)
		but[i]++;
	for(i=0;i<tmp_cont;i++)
	{
		printf(" %d", but[i]);
	}
	printf("\n");
	return 0;
}

int cont_num(char *str, char *zstr, int *cont)
{
	int tmp_cont = 0;
	char *tmp=str;
	int i;
	
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
	printf("tmp_cont is %d\n", tmp_cont);

}

int main(void)
{
	char *str="aa,bbbb,cc,dd,aa,cc,aa,32165,";
	char *zstr=",";
	int cont = 0;
	int ret = 0;
	cont_num(str, zstr, &cont);
	str_cout(str, zstr, cont);
	
	return 0;
}
