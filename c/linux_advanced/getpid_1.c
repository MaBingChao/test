#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//pid_t getpid(void);

int main(int argc, char *argv[])
{
	pid_t pid;
	
	pid = getpid();
	
	printf("pid is %d\n", pid);
	return 0;
}