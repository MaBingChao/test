#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define FILE_S "/home/work/blue/work/test/c/file/f1.txt"
#define FILE_T "/home/work/blue/work/test/c/file/f2.txt"

//int open(const char *pathname, int flags);
//int open(const char *pathname, int flags, mode_t mode);
//ssize_t read(int fd, void *buf, size_t count);
//ssize_t write(int fd, const void *buf, size_t count);


//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

int main(int argc, char *argv[])
{
	int fp_s;
	int fp_t;
	int ret;
	//	char buf[1024] = {0};
	char buf[10] = {0};
	fp_s = open(FILE_S, O_RDWR | O_CREAT, 755);
	if(!fp_s)
	{
		//perror("fopen");
		perror(FILE_S);
		return -1;
	}
	fp_t = open(FILE_T, O_RDWR | O_CREAT, 755);
	if(!fp_t)
	{
		//perror("fopen");
		perror(FILE_T);
		return -1;
	}

	while(1)
	{
		//fread success return 0
		//ret = fread(buf, sizeof(buf), 1, fp); 
		ret = read(fp_s, buf, sizeof(buf)-1);
		if(ret)
		{
			write(fp_t, buf, sizeof(buf)-1);
		}
		else
			break;
		
	}

	close(fp_s);
	close(fp_t);
	return 0;
}
