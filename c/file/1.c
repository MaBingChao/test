#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "/home/work/blue/work/test/c/file/f1.txt"


//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

int main(int argc, char *argv[])
{
	FILE *fp;
	int ret;
	//	char buf[1024] = {0};
	char buf[10] = {0};
	fp = fopen(FILE_PATH, "r");
	if(!fp)
	{
		//perror("fopen");
		perror(FILE_PATH);
		return -1;
	}

	while(!feof(fp))
	{
		//fread success return 0
		//ret = fread(buf, sizeof(buf), 1, fp); //不减1的话会多出来一个乱码
		ret = fread(buf, sizeof(buf)-1, 1, fp);
		printf("%s", buf);
	}

	fclose(fp);
	return 0;
}
