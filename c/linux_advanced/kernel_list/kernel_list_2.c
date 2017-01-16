#include <stdio.h>
#include <string.h>


typedef struct student
{
	int i;
	char name[20];
	int j;
	
}STU;

int main(void)
{
	STU *stu = NULL;
	int ret;
	stu = malloc(sizeof(STU));
	stu->i = 100;
	stu->j = 1000;
	strcpy(stu->name, "aaaaaa");
	
	//STU *tmp = 0;
	//ret = &(tmp->j);
	//将STU 映射到0地址处，求偏移量
	ret = &(((STU *)0)->j);
	
	printf("ret = %d\n", ret);

	
	return 0;
}
