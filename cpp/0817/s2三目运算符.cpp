#include <iostream>

using namespace std;

int main(void)
{
	int a = 10;
	int b = 20;
	
	// C++ 编译器，三目运算符表达式返回的变量本身，即返回a 而不是a的值10
	(a < b ? a : b) = 30;
	
	cout << "a = " << a << endl;
	
	return 0;
}