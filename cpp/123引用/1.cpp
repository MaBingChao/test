#include <iostream>

int main(void)
{	
	int aaaa;
	int &a = aaaa;
	aaaa = 999;
	std::cout << "&aaaa " << &aaaa <<std::endl;
	std::cout << "&a" << &a <<std::endl;
	a = 0;
	std::cout << "aaaa" << aaaa <<std::endl;
	std::cout << "a" << a <<std::endl;


	return 0;
}
