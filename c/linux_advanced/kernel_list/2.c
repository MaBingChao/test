#include <stdio.h>
#include <unistd.h>
#include "list.h"


typedef struct student
{
	int id;
	char name[20];
	struct list_head list;
	
}STU;

int main(int argc, char *argv[])
{
	list_head *tmp;
	STU stu1, stu2, stu3;
	stu1.id = 1;
	strcpy(stu1.name, "aaa");
	
	stu2.id = 2;
	strcpy(stu2.name, "bbb");
	
	stu3.id = 3;
	strcpy(stu3.name, "ccc");
	
	printf("stu1 id name : %d %s\n", stu1.id, stu1.name);
	
	INIT_LIST_HEAD(&stu1.list);
	list_add(&stu2.list, &stu1.list);
	list_add(&stu3.list, &stu1.list);
	
	tmp = &stu1.list;
	while(tmp->next != tmp)
	{
		//list_entry(pos,struct student,list);
		printf("stu1 id name : %d %s\n", stu1.id, stu1.name);
		tmp = tmp->next;
	}
	
	return 0;
}