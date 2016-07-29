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


Techer *malloc_mmc(Techer **techer, int num)
{
	Techer *te = NULL;
	char **tmp = NULL;
	int i;
	int j;

	te = (Techer *)malloc(sizeof(Techer) * num);
	if(te == NULL)
	{
		printf("malloc techer[%d] err!\n",i);
		return NULL;
	}
	
	for(i = 0; i < num; i++)
	{
		te[i].name = (char *)malloc(sizeof(char) * 20);
		if(te[i].name == NULL)
		{
			printf("malloc techer[%d].name err!\n",i);
			return NULL;
		}
		
		tmp = NULL;
		tmp = (char **)malloc(sizeof(char **) * 2);
		if(tmp == NULL)
		{
			printf("malloc tmp err!\n",i);
			return NULL;
		}
		for(j = 0; j < 2; j++)
		{
			tmp[i] = (char *)malloc(sizeof(char) * 20);
			if(tmp[i] == NULL)
			{
				printf("malloc tmp[%d] err!\n",i);
				return NULL;
			}
		}
		te[i].bname = tmp;
	}
	*techer = te;
}

void free_mmc(Techer *techer, int num)
{
	Techer *te = techer;
	int i;
	int j;
	char **tmp;
	
	for(i = 0; i < num; i++)
	{
		if(te[i].name != NULL)
		{
			free(te[i].name);
		}
		
		tmp = te[i].bname;
		if(tmp != NULL)
		{
			for(j = 0; j < 2; j++)
			{
				if(tmp[j] != NULL)
				{
					free(tmp[j]);
				}
			}
		}
		free(tmp);
		te[i].bname = NULL;
	}
	if(te != NULL)
	{
		free(te);
	}	
}

void free_mmc2(Techer **techer, int num)
{
	Techer *te = *techer;
	int i;
	int j;
	char **tmp;
	
	for(i = 0; i < num; i++)
	{
		if(te[i].name != NULL)
		{
			free(te[i].name);
		}
		
		tmp = te[i].bname;
		if(tmp != NULL)
		{
			for(j = 0; j < 2; j++)
			{
				if(tmp[j] != NULL)
				{
					free(tmp[j]);
				}
			}
		}
		free(tmp);
		te[i].bname = NULL;
	}
	if(te != NULL)
	{
		free(te);
	}	
	
	*techer = NULL;
}

int main(int argc, char *argv[])
{
	int i;
	int j;
	Techer *techer = NULL;	

	malloc_mmc(&techer, NUM);
	for(i = 0; i < NUM; i++)
	{
		printf("input techer[%d] name :\n",i);
		scanf("%s",techer[i].name);
	}
	
	for(i = 0; i < NUM; i++)
	{
		printf("input techer[%d] name : %s\n", i, techer[i].name);
	}
	//free_mmc(techer, NUM);
	free_mmc2(&techer, NUM);

	return 0;
}

