// InheritanceExample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

class B1 {
	int a;
public:
	B1() { std::cout << "object of " << typeid(*this).name() << " was created\n"; }
	B1(int x) :B1() { a = x; }
	~B1() { std::cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class B2 {
	int b;
public:
	B2() { std::cout << "object of " << typeid(*this).name() << " was created\n"; }
	B2(int x) :B2() { b = x; }
	~B2() { std::cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D1 : private B1, public B2 {
	int c;
public:
	D1(int x, int y, int z) : B1(y), B2(z)
	{
		c = x;
		std::cout << "object of " << typeid(*this).name() << " was created\n";
	};
	~D1() { std::cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D2 : public B1, private B2 {
	int d;
public:

	D2(int x, int y, int z) : B1(y), B2(z)
	{
		d = x;
		std::cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D2() { std::cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D3 : private D1, public D2 {
	int e;
public:
	D3(int x, int y, int z, int i, int j, int k, int l) : D1(y, z, i), D2(j, k, l)
	{
		e = x;
		std::cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D3() { std::cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

int main()
{
	D3 temp(1, 2, 3, 4, 5, 6, 7);
    return 0;
}

