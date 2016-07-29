#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 3

typedef struct Techer
{
	int id;
	char *name;
	char **bname;
}Techer;

Techer *malloc_mmc(Techer **te)
{
	Techer *techer = NULL;
	int i;
	int j;

	techer = (Techer *)malloc(sizeof(Techer) * NUM);
	if(techer == NULL)
	{
		perror("malloc");
		return NULL;
	}

	for(i = 0; i < NUM; i++)
	{
		techer[i].name = (char *)malloc(sizeof(char) * 10);
		if(techer[i].name == NULL)
		{
			printf("techer[%d].name malloc error!\n",i);
			return NULL;
		}

		/* 用临时变量指向bname二位指针
		   tmp = (char **)malloc(sizeof(char*) * 2);
		   if(tmp == NULL)
		   {
		   printf("techer[%d].bname malloc error!\n",i);
		   return NULL;
		   }
		   for(j = 0; j < 2; j++)
		   {
		   tmp[j] = (char *)malloc(sizeof(char) *10);
		   }
		   techer[i].bname = tmp;
		 */
		techer[i].bname = (char **)malloc(sizeof(char*) * 2);
		if(techer[i].bname == NULL)
		{
			printf("techer[%d].bname malloc error!\n",i);
			return NULL;
		}
		for(j = 0; j < 2; j++)
		{
			techer[i].bname[j] = (char *)malloc(sizeof(char) *10);
		}
	}
	*te = techer;
	return techer;
}

/* input */
int Input(Techer *te)
{
	Techer *techer = te;
	int i;
	int j;
	for(i = 0; i < 3; i++)
	{
		printf("please input techer[%d] name:\n", i);
		scanf("%s", techer[i].name);
		for(j = 0; j < 2; j++)
		{
			printf("please input techer[%d] bname[%d]:\n", i, j);
			scanf("%s", techer[i].bname[j]);
		}
	}
}

int Output(Techer *te)
{
	Techer *techer = te;
	int i;
	int j;
	for(i = 0; i < 3; i++)
	{
		printf(" techer[%d] name: %s\n", i, techer[i].name);
		for(j = 0; j < 2; j++)
		{
			printf(" techer[%d] bname[%d]: %s\n", i, j, techer[i].bname[j]);
		}
	}
}

void Free_mmc(Techer *te)
{
	Techer *techer = te;
	int i;
	int j;

	for(i = 0; i < NUM; i++)
	{
		free(techer[i].name);
	}

	for(i = 0; i < NUM; i++)
	{
		char **tmp = techer[i].bname;
		for(j = 0; j < 2; j++)
		{
			free(tmp[j]);
		}
		free(tmp);
		techer[i].bname = NULL;
	}
	free(techer);
}
int main(int argc, char *argv[])
{
	int i,j;
	char **tmp = NULL;
	Techer *techer = NULL;

	malloc_mmc(&techer);
	Input(techer);
	Output(techer);

	Free_mmc(techer);


	return 0;
}
