#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_cout(char *str, const char *zstr, int cont, int **bbut)
{
	int tmp_cont = cont;	
	int *but = NULL;
	char *tmp = str;
	char *tmp1 = str;
	char *tmp2 = NULL;
	int i;

	but = (int *)malloc(cont * sizeof(int));

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

	*bbut = but;

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

int malloc_mem(char ***socstr, int cont, int *but)
{
	int i;
	char **array = NULL;

	array = (char **)malloc(cont * sizeof(char *));
	if(array == NULL)
	{
		return -1;
	}

	for(i = 0; i < cont; i++)
	{
		array[i] = (char *)malloc(but[i] * sizeof(char));
		if(array[i] == NULL)
		{
			return -2;
		}
	}

	*socstr = array;
}

int Jstr(char ***socstr, char *str, int *but, int cont)
{
	char **tmpsocstr = *socstr;
	int i;
	int j;
	for(i=0;i<cont;i++)
	{
		for(j=0;j<but[i]-1;j++)
		{
			tmpsocstr[i][j] = *str++;
		}
		tmpsocstr[i][j] = '\0';
		str += 1;
	}
}

int main(void)
{
	char *str="aa,bbbb,casdf,fasdfg,1234,c,dd,aa,cc,aa";
	char *zstr=",";
	int cont = 0;
	int *but = NULL;
	char **socstr = NULL;
	int i;


	cont_num(str, zstr, &cont);
	str_cout(str, zstr, cont, &but);

	malloc_mem(&socstr, cont, but);

	Jstr(&socstr, str, but, cont);

	for(i = 0; i < cont; i++)
		{
			printf("%s \n", socstr[i]);
		}

	return 0;
}
