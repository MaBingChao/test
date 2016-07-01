#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	printf("%d\n", tmp_cont);
}

int cont_snum(int **bbut, char *str, const char *zstr, int cont)
{
	char *tmp1 = str;
	char *tmp2 = str;
	char *tmp3 = NULL;
	int *but = *bbut;
	int i;

	for(i = 0; i < cont; i++)
	{
		tmp1 = strstr(tmp1, zstr);
		if(tmp1 == NULL)
			break;
		but[i] = strlen(tmp2) - strlen(tmp1)+1;
		tmp1 += strlen(zstr);
		tmp2 = tmp1;
	}
	but[i] = strlen(tmp2)+1;

	
	for(i = 0; i < cont; i++)
		{
			printf("%d	 ", but[i]);
		}
		printf("\n");
}



int main(void)
{
	char *str="sd,fsdf,aasdfsdaa,465aa,654,654a,asd,fsd,faa,6545";
	char *zstr=",";
	int cont = 0;
	int *but = NULL;
	char **socstr = NULL;
	int i;
	int j;


	cont_num(str, zstr, &cont);

	but = (int *)malloc(cont * sizeof(int));
	cont_snum(&but, str, zstr, cont);


	

	char *tmp = str;
	socstr = (char **)malloc(cont * sizeof(char *));

	for(i = 0; i < cont; i++)
	{
		for(j = 0; j < but[i]; j++)
			socstr[i] = (char *)malloc(but[i] * sizeof(char));
	}

	for(i = 0; i < cont; i++)
	{
		for(j = 0; j < but[i]-1; j++)
		{
			socstr[i][j] = *tmp++;
		}
		socstr[i][j] = '\0';	//此时tmp指向 ","或者zstr指定的分隔符，需要向后移动strlen(zstr)
		tmp = tmp+strlen(zstr);
		printf("%s \n", socstr[i]);
	}


	free(but);
	but = NULL;
	return 0;
}
