#include <stdio.h>

typedef struct student
{
	int i;
	char name[20];
	int j;
	
}STU;

int main(void)
{
	STU *stu;
	
	stu = (STU *)malloc(sizeof(STU));
	stu->i = 10;
	strcpy(stu->name, "aaaa");
	stu->j = 20;
	int ret;
	
	// stu->j 的真是地址
	int *p1 = &(stu->j);
	printf("p1 %d\n", p1);
	printf("p1 %p\n", p1);
	STU *p2;

	// 相对偏移量
	ret = (int)&((STU *)0)->j;
	printf("%d\n", ret);

	// 一定要将p1强转为 char*
	p2 = (STU *)((char *)p1-ret);
	printf("p2 %d\n", p2);
	printf("p2 %p\n", p2);
	printf("p2->i %d\n", p2->i);
	
	free(stu);

	return 0;
}
