#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

int main(void)
{
	int a = 10;
	pid_t pid;
	char *name;
	
	
	pid = fork();
	if(pid < 0)
	{
		perror("fork");
	}
	else if(pid == 0)
	{
		name = "aaaaaa\n";
		a = 11;
	}
	else
	{
		name = "bbbbbbbbbb\n";
		a = 12;
	}
	printf("a = %d..\n", a);
	printf(name);
	
	
	return 0;
}