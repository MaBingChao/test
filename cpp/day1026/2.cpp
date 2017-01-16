#include <iostream>
using namespace std;

class a
{
	public:
	void hello(){cout << "a +++hello" << endl;}
	void hello(int a){cout << "a chongzai +++hello" << endl;}
};

class b : public a
{
	public:
	void hello(){cout << "b +++hello" << endl;}
	void print(){cout << "b +++print" << endl;}
	
};


int main(void)
{
	b b1;
	
	b1.hello();
	b1.a::hello();
	b1.a::hello(1);
	
	return 0;
}