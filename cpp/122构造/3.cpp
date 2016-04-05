#include <iostream>
#include <string>

class demo
{
public :
	int tmp;
	demo(int i){x=i;};
	demo(demo&t){x=t.x;};
	int get(){return x;}
	void set(int i){x=i;}
	void print(){std::cout <<x <<"\n";}
	~demo(){};
private :
	int x;
};

int main(void)
{
	demo a(10);	
	a.print();
	demo b(a);
	b.print();
	return 0;
}
