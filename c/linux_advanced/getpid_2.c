#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//pid_t getpid(void);

#define SIZEBUFF 1024

int main(int argc, char *argv[])
{

	char buf[SIZEBUFF];
	int ret;
	
	//char *fgets(char *s, int size, FILE *stream);
	while(fgets(buf, SIZEBUFF, stdin) != NULL)
	{
		printf("%s\n", buf);
		
	}
	return 0;
}