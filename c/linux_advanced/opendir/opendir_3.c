#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

       

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("please input : ./a.out XXX\n");
		return -1;
	}
	
	DIR *dp;
	struct dirent *dp_dir;
	struct stat buf;
      // DIR *opendir(const char *name);
	  // int closedir(DIR *dirp);
	  // struct dirent *readdir(DIR *dirp);
	  // int stat(const char *path, struct stat *buf);	
	if((dp = opendir(argv[1])) == NULL)
	{
		printf("opendir filead\n");
		return -1;
	}
		
	dp_dir = readdir(dp);
	printf("%s\n", dp_dir->d_name);
	stat(dp_dir->d_name, &buf);
	printf("%d\n", buf.st_mode);	//st_mode的实际类型是一个 unsing int

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


struct stat {
    dev_t         st_dev;       //文件的设备编号
    ino_t         st_ino;       //节点
    mode_t        st_mode;      //文件的类型和存取的权限
    nlink_t       st_nlink;     //连到该文件的硬连接数目，刚建立的文件值为1
    uid_t         st_uid;       //用户ID
    gid_t         st_gid;       //组ID
    dev_t         st_rdev;      //(设备类型)若此文件为设备文件，则为其设备编号
    off_t         st_size;      //文件字节数(文件大小)
    unsigned long st_blksize;   //块大小(文件系统的I/O 缓冲区大小)
    unsigned long st_blocks;    //块数
    time_t        st_atime;     //最后一次访问时间
    time_t        st_mtime;     //最后一次修改时间
    time_t        st_ctime;     //最后一次改变时间(指属性)
};

*/