#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 8192
//如何选取BUFSIZE的值,见Unix高级编程p42
// ssize_t read(int fd, void *buf, size_t count);
// ssize_t write(int fd, const void *buf, size_t count);

int main(int argc, char *argv[])
{
	int ret;
	int tmp;
	char buf[BUFSIZE];
	
	// read 读了多少就返回多少,到文件末尾则返回0,错误返回-1
	while((ret = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
	{
		if(ret != (tmp = write(STDOUT_FILENO, buf, ret)))
		{
			perror("write");
			return -1;
		}
	}
	
	
	return 0;
}