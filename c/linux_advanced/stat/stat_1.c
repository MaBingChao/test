#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//int stat(const char *path, struct stat *buf);
//int fstat(int fd, struct stat *buf);
//int lstat(const char *path, struct stat *buf);


int main(int argc, char *argv[])
{
	int ret;
	struct stat buf;
	
	printf("please input ./a.out path\n");
	
	ret = stat(argv[1], &buf);
	
	if(S_ISREG(buf.st_mode)){
		printf("file\n");
	}else if(S_ISDIR(buf.st_mode)){
		printf("dir\n");
	}

	return 0;
}


#if 0
 struct stat {
               dev_t     st_dev;     /* ID of device containing file 设备号*/
               ino_t     st_ino;     /* inode number */
               mode_t    st_mode;    /* protection */
               nlink_t   st_nlink;   /* number of hard links */
               uid_t     st_uid;     /* user ID of owner */
               gid_t     st_gid;     /* group ID of owner */
               dev_t     st_rdev;    /* device ID (if special file) */
               off_t     st_size;    /* total size, in bytes */
               blksize_t st_blksize; /* blocksize for file system I/O */
               blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
               time_t    st_atime;   /* time of last access */
               time_t    st_mtime;   /* time of last modification */
               time_t    st_ctime;   /* time of last status change */
           };

#endif