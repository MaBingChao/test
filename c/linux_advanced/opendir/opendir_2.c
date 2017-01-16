#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
     

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("please input : ./a.out XXX\n");
		return -1;
	}
	
	DIR *dp;
	struct dirent *dp_dir;
      // DIR *opendir(const char *name);
	  // int closedir(DIR *dirp);
	  // struct dirent *readdir(DIR *dirp);
	//dp = opendir(argv[1]);
	if((dp = opendir(argv[1])) == NULL)
	{
		printf("opendir filead\n");
		return -1;
	}
	
	while(dp_dir = readdir(dp))
		printf("%s\n", dp_dir->d_name);
	
	closedir(dp);

	return 0;
}


/*

struct dirent
{
    ino_t d_ino; //d_ino 此目录进入点的inode
    ff_t d_off; //d_off 目录文件开头至此目录进入点的位移
    signed short int d_reclen; //d_reclen _name 的长度, 不包含NULL 字符
    unsigned char d_type; //d_type d_name 所指的文件类型 d_name 文件名
    har d_name[256];
};

返回值：成功则返回下个目录进入点. 有错误发生或读取到目录文件尾则返回NULL.


*/