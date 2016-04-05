#include <iostream>

class A
{
public :
	int get(int x);
	int ret(void);


};

int main(void)
{
	int a;
	int &ra = a;

	a=999;
	std::cout << "ra=" << ra << std::endl;
	std::cout << "a=" << a << std::endl;
	std::cout << "&ra=" << &ra << std::endl;
	std::cout << "&a=" << &a << std::endl;

	return 0;
}
