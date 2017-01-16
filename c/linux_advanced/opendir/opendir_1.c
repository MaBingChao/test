#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("please input : ./a.out XXX\n");
		return -1;
	}
	
	int fp1;

	fp1 = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0777);
	if(fp1 == -1)
	{
		perror("open");
		return -1;	
	}
	else
	{
		printf("fp1 is %d..\n", fp1);
	}
	

	return 0;
}
