#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
	
public:
	MyString()
	{
		len = 0;
		mstring = NULL;
	}
	MyString(int len)
	{
		this->len = len;
		this->mstring = new char[len+1];
	}
	MyString(int len, char *p)
	{
		this->len = len;
		this->mstring = new char[len+1];
		strcpy(this->mstring, p);
	}
public:
	void print(void)
	{
		cout << mstring << endl;
	}
	
public:
	MyString& operator=(const MyString &obj)
	{
		if(this->mstring != NULL)
		{
			delete [] this->mstring;
		}
		this->len = obj.len;
		stpcpy(this->mstring, obj.mstring);
	}
private:
	int len;
	char *mstring;
};

int main(void)
{
	char a[] = "bb";
	MyString ms1;
	
	MyString ms2(a);
	ms2.print();
	
	ms1 = ms2;
	ms1.print();
	
	return 0;
}