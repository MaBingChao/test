#include <iostream>
#include <stdlib.h>


using namespace std;

class Array
{
public:
friend ostream& operator<<(ostream &os, Array &obj);
friend void operator>>(istream &os, Array &obj);
	Array(int _len)
	{
		if(_len < 0)
		{
			len = 0;
			arraly = new int[len];
		}
		len = _len;
		
		// 分配一个int型变量，并初始化值为len
		// 等价于 int *p = malloc(int); *p=len;
		//arraly = new int(len);
		
		arraly = new int[len];
		//arraly = (int *)malloc(sizeof(int) * len);
	}
	//Array a1=a2;
	Array(const Array& obj)
	{
		if(obj.len < 0)
		{
			this->len = 0;
			this->arraly = new int[this->len];
		}
		
		this->len = obj.len;
		this->arraly = new int[this->len];
		
		for(int i = 0; i < this->len; i++)
		{
			this->arraly[i] = obj.arraly[i];
		}
	}
	~Array()
	{
		if(arraly != NULL)
		{
			delete [] arraly;
			//free(arraly);
		}
	}
	
public:
	//operator=(a1,a2)
	Array& operator=(Array &obj)
	{
		if(this->arraly != NULL)
		{
			delete [] this->arraly;
		}
		this->len = obj.len;
		this->arraly = new int[this->len];
		
		for(int i = 0; i < this->len; i++)
		{
			this->arraly[i] = obj.arraly[i];
		}
		return *this;
	}
	//重载数组下标[]   a[i]
	int& operator[](int i)
	{
		return this->arraly[i];
	}
	// 重载等等 a1==a2
	bool operator==(Array &a1)
	{
		if(this->len != a1.len)
		{
			return false;
		}
		for(int i=0; i < this->len; i++)
		{
			if(a1[i] != this->arraly[i])
			{
				return false;
			}
		}
		return true;
	}
	//重载不等号 a1!=a2
	//可以直接利用已经重载好的等等号
	bool operator!=(Array &a1)
	{
		/*
		if(*this == a1)
		{
			return false;
		}
		return true;
		*/
		return !(*this == a1);
	}
	
public:
	int get_len(void)
	{
		return len;
	}
	void setArray(int i, int num)
	{
		arraly[i] = num;
	}
	void printArray(int i)
	{
		cout << arraly[i] << " ";
	}

private:
	int len;
	int *arraly;
};

//cout << a1
ostream& operator<<(ostream &os, Array &obj)
{
	for(int i=0; i < obj.len; i++)
	{
		os << obj[i] << " ";
	}
	return os;
}
//cin >> a
void operator>>(istream &is, Array &obj)
{
	cout << "please input number:" << endl;
	for(int i=0; i < obj.len; i++)
	{
		is >> obj[i];
	}
}

int main(void)
{
	Array a1(5);
	Array a2(10);
	

	for(int i = 0; i < a1.get_len(); i++)
	{
		//a1.setArray(i, i+1);
		a1[i] = i;
	}
	
	for(int i = 0; i < a2.get_len(); i++)
	{
		//a2.setArray(i, i+10);
		a2[i] = i+10;
	}
	
	cout << a1;
	cin >> a1;
	cout << a1;
	return 0;
}