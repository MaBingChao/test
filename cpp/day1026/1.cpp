#include <iostream>
using namespace std;

//�������д��ڶ��ͬ������������

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
	// ��������Ĭ��ȥ��������ĳ�Ա�������������û�У��Ż�ȥ������
	// �ᱨ�� ������û��hello()��Ա���������ǻ���a��b���У������ԣ�,�����Ҫָ�����Ǹ������
	// c1.hello();
	c1.b::hello();
	
	// ��������Ĭ��ȥ��������ĳ�Ա����
	c1.print();
	c1.b::print();
	
	return 0;
}