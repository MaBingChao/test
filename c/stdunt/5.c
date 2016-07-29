/*
 * 双向循环链表
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILE_NAME "/home/work/blue/work/test/c/stdunt/1.txt"

typedef struct Student 
{
	char name[20];
	int id;
	struct Student *prev;
	struct Student *next;

}Stu;


//头结点 插入完成后，头结点成为第一个节点
//并且它的值为0，因此不打印，不写入文件
Stu *Creat_head_node()
{
	Stu *tmp = NULL;
	
	tmp = (Stu *)malloc(sizeof(Stu));
	if(tmp == NULL)
	{
		perror("stu");
		return ;
	}
	memset(tmp, 0, sizeof(Stu));
	tmp->next = tmp->prev = tmp;
	return tmp;
}

//在头部插入新节点
Stu *add_new_node_head(Stu **head)
{
	Stu *tmp = *head;
	Stu *new = NULL;
	
	new = (Stu *)malloc(sizeof(Stu));
	if(new == NULL)
	{
		perror("stu");
		return ;
	}
	memset(new, 0, sizeof(Stu));
	
	new->next = tmp->next;
	tmp->next->prev = new;
	new->prev = tmp;
	tmp->next = new;
	
	printf("please new stu name:\n");
	scanf("%s", new->name);	
	
	printf("please new stu id:\n");
	scanf("%d", &new->id);	
	
	return tmp;
}

//在尾部插入新节点
Stu *add_new_node_end(Stu **head)
{
	Stu *tmp = *head;
	Stu *new = NULL;
	Stu *end = NULL;
	
	if(tmp == NULL)
	{
		return NULL;
	}
	
	/*找到最后一个结点*/
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	end = tmp;
	
	new = (Stu *)malloc(sizeof(Stu));
	if(new == NULL)
	{
		perror("stu");
		return ;
	}
	memset(new, 0, sizeof(Stu));
	
	new->next = end->next;
	end->next = new;
	
	printf("please new stu name:\n");
	scanf("%s", new->name);	
	
	printf("please new stu id:\n");
	scanf("%d", &new->id);	

	return tmp;
}


/* 逆序 1 
*
* 每一次循环完成，p3指向p2的下一个
* 最后一个节点没有连接起来，在循环体外连接
******************************************/

int N_stort_1(Stu **student)
{
	Stu *p1 = NULL;
	Stu *p2 = *student;
	Stu *p3 = p2->next;
	
	while(p3 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;	//处理最后一个节点
	*student = p2;
}

/* 逆序 2 
*
* 每一次循环完成，p2和p3指向同一个
* 循环完成后，p2和p3都指向NULL，p1指向最后一个
******************************************/
int N_stort_2(Stu **student)
{
	Stu *p1 = NULL;
	Stu *p2 = *student;
	Stu *p3 = NULL;
	
	while(p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	
	*student = p1;
}

/* 逆序 2 递归
*
* 每一次循环完成，p2和p3指向同一个
* 循环完成后，p2和p3都指向NULL，p1指向最后一个
******************************************/
Stu *N_stort_3(Stu *student)
{
	
}

/* 打印 */
void printf_node(Stu *student)
{
	Stu *tmp = student->next;
	//头结点 插入完成后，头结点成为最后一个节点
	//并且它的值为0,第一个结点不打印，不写入文件
	for(; tmp != NULL; tmp = tmp->next)
	{
		printf("%s \t %d\n", tmp->name, tmp->id);
	}
}

int main(int argc, char *argv[])
{
	Stu *head = NULL;
	head = Creat_head_node();
	
	
	printf_node(head);
		
	return 0;
}
