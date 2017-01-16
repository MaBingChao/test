#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//int open(const char *pathname, int flags);
//int open(const char *pathname, int flags, mode_t mode);

//int creat(const char *pathname, mode_t mode);
//ssize_t write(int fd, const void *buf, size_t count);
//off_t lseek(int fd, off_t offset, int whence);

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	
	char buf1[] = "asdfghasdg";
	char buf2[] = "2342345343";
	
	
	if(argc != 2)
	{
		printf("please input...!!  \nEg: ./a.out 1.txt\n");
		return -1;
	}
	//creat 和 open 都是返回文件描述符
	//创建一个文件并以只写的方式打开。如果原来该文件存在，会将这个文件的长度截短为0。
	if(-1 == (fd = creat(argv[1], 777)))
	{
		perror("creat");
		return -1;
	}

	//write err 返回-1; success 返回写的个数
	if(strlen(buf1) != (ret = write(fd, buf1, strlen(buf1))))
	{
		perror("write");
		return -1;
	}
	
	//中间 30个的会补全0,可以使用 od -c argv[1]查看文件argv[1]
	//if(-1 == (ret = lseek(fd, 10, SEEK_SET)))
	if(-1 == (ret = lseek(fd, 40, SEEK_SET)))
	{
		perror("lseek");
		return -1;
	}
	
	if(strlen(buf2) != (ret = write(fd, buf2, strlen(buf2))))
	{
		perror("write");
		return -1;
	}
	return 0;
}

