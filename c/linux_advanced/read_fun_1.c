#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 100

int main(int argc, char *argv[])
{
	int ret;
	char buf[BUFSIZE];
/*	
	ret = read(0, buf, sizeof(buf));
	if(ret)
	{
		write(1, buf, ret);
	}
*/	
	ret = read(STDIN_FILENO, buf, sizeof(buf));
	if(ret)
	{
		write(STDOUT_FILENO, buf, ret);
	}
	
	return 0;
}