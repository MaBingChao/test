#include <iostream>
using namespace std;

//派生类中存在多个同名函数的问题

class a
{
	public:
	void hello(){cout << "a +++hello" << endl;}
	
};

class b
{
	public:
	void hello(){cout << "b +++hello" << endl;}
	void print(){cout << "b +++print" << endl;}
	
};

class c : public a, public b
{
	public:
	void print(){cout << "c +++print" << endl;}
	
};

int main(void)
{
	c c1;
	// 编译器会默认去调用子类的成员函数，如果子类没有，才会去基类找
	// 会报错 。子类没有hello()成员函数，但是基类a和b都有（二义性）,因此需要指明是那个基类的
	// c1.hello();
	c1.b::hello();
	
	// 编译器会默认去调用子类的成员函数
	c1.print();
	c1.b::print();
	
	return 0;
}