#include <iostream>
#include <locale>

int main(void)
{
	setlocale(LC_ALL, "chs");
	wchar_t wt[]=L"中";
	std::wcout << wt << "\n";
	return 0;
}
