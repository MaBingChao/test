#include <iostream>

int main(void)
{	
	int i;
	for(i = 0; i < 128 ; i++){
		std::cout << char(i) << " ";
	}

	std::cout << std::endl;

	return 0;
}
