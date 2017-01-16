#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 获取随机数
#include <stdlib.h>

int rand(void);
0~RAND_MAX之间的一个随机数，其中RAND_MAX 是stdlib.h 中定义的一个整数
#define RAND_MAX 0x7FFF
其值最小为0,最大为32767（与编译系统有关）

int rand_r(unsigned int *seedp);
获取随机数种子
void srand(unsigned int seed);
*/

/* **************************************************
 * a + rand() % n
 * 取值范围从 a-n 之间的整数 对n取余
 * rand()产生的随机数在每次运行的时候都是与上一次相同的,便于程序的调试
 * 若要产生每次不同的随机数，可以使用srand( seed )函数进行随机化，随着seed的不同，就能够产生不同的随机数
 * 还可以包含time.h头文件，然后使用srand(time(0))来使用当前时间使随机数发生器随机化(只要两次运行的间隔超过1秒)
 *****************************************************/
int main(void)
{
	int i;
	int a[10] = {0};
	
	//srand(time(0));
	//srand(1);
	//srand(2);
	for(i = 0; i < 10; i++)
	{
		a[i] = 1+rand() % 10;
	}
	
	for(i = 0; i < 10; i++)
	{
		printf("%d, ", a[i]);
	}
	
	printf("\n");
	return 0;
}