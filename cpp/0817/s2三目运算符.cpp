#include <iostream>

using namespace std;

int main(void)
{
	int a = 10;
	int b = 20;
	
	// C++ ����������Ŀ��������ʽ���صı�������������a ������a��ֵ10
	(a < b ? a : b) = 30;
	
	cout << "a = " << a << endl;
	
	return 0;
}