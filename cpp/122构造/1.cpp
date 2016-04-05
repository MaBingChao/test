#include <iostream>
#include <string>

class rectangle
{
public :
	rectangle(){std::cout << "gou zao\n";};
	rectangle(int l, int w){std::cout << "l = " << l << "\t" << "w = " << w << "\n" << "mian ji =" << l*w << std::endl;};
};

int main(void)
{
	rectangle a;
	rectangle b(7,2);

	return 0;
}
