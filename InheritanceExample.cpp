// InheritanceExample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

class B1
{
	int a;
public:
	B1() { std::cout << "object of" << typeid(*this).name() << " was created\n"; }
	B1(int x) :B1() { a = x; }
	~B1() { std::cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class B2
{
	int b;
public:
	B2() { std::cout << "object of" << typeid(*this).name() << " was created\n"; }
	B2(int x) :B2() { b = x; }
	~B2() { std::cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D1 : protected B1
{
	int c;
public:
	D1(int x, int y) : B1(y)
	{
		c = x;
		std::cout << "object of" << typeid(*this).name() << " was created\n";
	};
	~D1() { std::cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};
	
class D2 : public B1 
{
	int d;
public:
	D2(int x, int y) : B1(y)
	{
		d = x;
		std::cout << "object of" << typeid(*this).name() << " was created\n";
	};
	~D2() { std::cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D3 : protected D2, protected B2 
{
	int e;
public:
	D3(int x, int y, int z, int i) : D2(y, z), B2(i)
	{
		e = x;
		std::cout << "object of" << typeid(*this).name() << " was created\n";
	}
	~D3() { std::cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D4 : public D1, public D3
{
	int f;
public:
	D4(int x, int y, int z, int i, int j, int k, int l) : D1(y, z), D3(z, i, k, l)
	{
		f = x;
		std::cout << "object of" << typeid(*this).name() << " was created\n";
	}
	~D4() { std::cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

int main()
{
	D3 temp(100, 200, 300, 400);
	D4 temp1(1, 2, 3, 4, 5, 6, 7);
	return 0;
}

