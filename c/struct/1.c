#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUT 3
#define ZBUT 4
#define NAME 20
#define BNAME 30

typedef struct Techer 
{	
	int id;
	char *name;
	char **bname;
}Techer;

int malloc_mmc(Techer **tech)
{
	int i;
	int j;
	Techer *tmp = NULL;
	tmp = (Techer *)malloc(sizeof(Techer) * BUT);
	if(tmp == NULL)
	{
		return -1;
		perror("malloc");
	}

	for(i = 0; i < BUT; i++)	
	{
		tmp[i].name = (char *)malloc(NAME * sizeof(char));
	}

	for(i = 0; i < BUT; i++)	
	{
		char **tbname = NULL;
		tbname = (char **)malloc(ZBUT * sizeof(char *));
		for(j = 0; j < ZBUT; j++)
		{
			tbname[j] = (char *)malloc(BNAME * sizeof(char));
		}
		tmp[i].bname = tbname;
	}
	*tech = tmp;
}

void fmalloc_mmc(Techer **ther)
{
	int i;
	int j;

}

int main(int argc, char *argv[])
{
	int i;
	int j;
	Techer *tech=NULL;
	Techer **ftech=NULL;
	char **tmp = NULL;

	malloc_mmc(&tech);

	for(i = 0; i < BUT; i++)
	{
		printf("please input tech[%d] name:\n", i);
		scanf("%s", tech[i].name);
	}

	for(i = 0; i < BUT; i++)
	{
		for(j = 0; j < ZBUT; j++)
		{
			printf("please input tech[%d] bname[%d]:\n", i,j);
			scanf("%s", tech[i].bname[j]);
		}
	}

	for(i = 0; i < BUT; i++)
	{
		printf("%s\n", tech[i].name);

	}

	for(i = 0; i < BUT; i++)
	{
		free(tech[i].name);
	}

	for(i = 0; i < BUT; i++)
	{
		tmp = tech[i].bname;
		for(j = 0; i < ZBUT; j++)
		{
			free(tmp[j]);
		}
	}
	free(tmp);
	tech[i].bname = NULL;

	return 0;
}
