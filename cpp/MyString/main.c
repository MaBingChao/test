#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
public:
	//�մ� = ""
	//MyString a3()
	MyString()
	{
		len = 0;
		p = new char[len + 1];
		strcpy(p, "");
	}
	//MyString a3(NULL)
	//MyString a3("aaaa")
	//aaaaa���ַ������� ����ʹ��const����
	MyString(const char *Pobj)
	{
		if(Pobj == NULL)
		{
			len = 0;
			p = new char[len + 1];
			strcpy(p, "");
		}
		else
		{
			len = strlen(Pobj);
			p = new char[len + 1];
			strcpy(p, Pobj);
		}
	}
	MyString(const MyString &Pobj)
	{
		
		len = Pobj.len;
		p = new char[len + 1];
		strcpy(p, Pobj.p);

	}
	~MyString()
	{
		if(p != NULL)
		{
			len = 0;
			delete p;
		}
	}
	
public:
	//a1=a2
	MyString& operator=(const MyString &obj)
	{
		len = obj.len;
		p = new char[len + 1];
		strcpy(p, obj.p);
		
		return *this;
	}
	
	//a1 == a2
	//���������const ������ this ָ���
	bool operator==(const MyString &obj) const
	{
		if(len != obj.len)
		{
			return false;
		}
		//strcmp ���ʱ����0
		//���Ƚ�s1��һ���ַ�ֵ��ȥs2��һ���ַ�ֵ
		//s1����s2 ����������С�ڷ��ظ���
		if(strcmp(p, obj.p))
		{
			return false;
		}
		return true;
	}
	bool operator!=(const MyString &obj) const
	{
		return !(p == obj.p);
	}
	
	
public:
	void print()
	{
		cout << p << endl;
	}
private:
	int len;
	char *p;
};

ostream& operator<<(ostream &os, const MyString &obj)
{
	os << obj.p;
	
	return os;
}

int main(void)
{
	
	MyString mys1;
	MyString mys2("aaaaa");
	MyString mys3 = mys2;
	
	cout << (mys1 == mys2) << endl;
	cout << (mys2 == mys3) << endl;
	//mys1.print();
	mys2.print();
	mys3.print();
	return 0;
}