#include <iostream>

class A
{
public:
	A();
	~A();
	A(A&);
};

A::A()
{
	std::cout<< "调用构造函数" <<std::endl;
}
A::~A()
{
	std::cout<< "调用析构函数" <<std::endl;
}
A::A(A&)
{
	std::cout<< "该类被当做参数传递是，调用次复制构造函数" <<std::endl;
}

int one(A one)
{
	return 0;
}
int two(A *one)
{
	return 0;
}
A stree(A *one)
{
	return *one;
}
A* fore(A *one)
{
	return one;
}

int main(void)
{	
	A a;
//	one(a);
//	one(a);
//	two(&a);	
//	two(&a);	
//	stree(&a);
//	stree(&a);
	fore(&a);
	fore(&a);
	
	return 0;
}
