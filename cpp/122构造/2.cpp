#include <iostream>
#include <string>

class demo
{
public :
	int tmp;
	demo(){x=2;std::cout << "dem 无参数的构造函数中的X=2\t" << x <<std::endl;};
	demo(int i){x=i;std::cout << "dem 有参数的构造函数中的X=i\t" << x << std::endl;};
	int get(){return x;}
	void set(int i){x=i;}
	~demo(){};
private :
	int x;
};

int main(void)
{
	demo a;	
	a.set(999);
	a.tmp = a.get();
	std::cout << a.tmp <<std::endl;
	//****************************

	demo b(10);
	b.set(1000);
	b.tmp=b.get();
	std::cout << b.tmp <<std::endl;
	

	return 0;
}
