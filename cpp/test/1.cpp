#include <iostream>



namespace a
{
	int b = 10;
}
namespace aa
{
	int b = 100;
}
int main(void)
{
	std::cout << "aaaaaaaaa" << std::endl;
	std::cout << a::b <<std::endl;
	std::cout << aa::b << "\n";
	
	return 0;
}
