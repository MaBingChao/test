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
	char *buf = "aaaaabbbbbccccc";
	fp = fopen(FILE_PATH, "w");
	if(!fp)
	{
		//perror("fopen");
		perror(FILE_PATH);
		return -1;
	}
	ret = fprintf(fp, "%s", buf);
	printf("%s", buf);


	fclose(fp);
	return 0;
}
