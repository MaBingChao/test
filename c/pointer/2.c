#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_arr(char *str1, char *str2, int *cont)
{
	char *tmp = str1;
	int count=0;
	while(*tmp != '\0')
	{
		tmp = strstr(tmp,str2);
		if(tmp == NULL)
		{   
			break;
			return -1; 
		}  
		tmp += 4;
		count++;
	}  
	*cont = count;
	
	return 0;
}

int main(void)
{    
        char *str = "aaabcd12abc33abcd3abddabcdabcd1";
        char *zstr = "abcd";
        int cont = 0;
        int ret = 0;	
        
	ret = str_arr(str, zstr, &cont);
	printf("cont is %d\n", cont);
		
        return 0;
}
