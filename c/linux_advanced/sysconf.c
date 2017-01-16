#include <stdio.h>
#include <unistd.h>

//long sysconf(int name);

int main(void)
{

	printf("%d\n", sysconf(1));

	return 0;
}
