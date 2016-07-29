#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_S "/home/work/blue/work/test/c/file/f1.txt"
#define FILE_T "/home/work/blue/work/test/c/file/f2.txt"


//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

int main(int argc, char *argv[])
{
	FILE *fp_s;
	FILE *fp_t;
	int ret;
	//	char buf[1024] = {0};
	char buf[10] = {0};
	fp_s = fopen(FILE_S, "r");
	if(!fp_s)
	{
		//perror("fopen");
		perror(FILE_S);
		return -1;
	}
	fp_t = fopen(FILE_T, "w");
	if(!fp_t)
	{
		//perror("fopen");
		perror(FILE_T);
		return -1;
	}

	do{
		//fread success return 0
		//ret = fread(buf, sizeof(buf), 1, fp);
		ret = fread(buf, sizeof(buf)-1, 1, fp_s);
		printf("%s\n", buf);
		if(ret)
		{
			fwrite(buf, sizeof(buf)-1, ret, fp_t);
		}
	
	}while(!feof(fp_s));

	fclose(fp_s);
	fclose(fp_t);
	return 0;
}
