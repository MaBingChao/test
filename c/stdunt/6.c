#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}


int main(int argc, char *argv[])
{
		
	return 0;
}
