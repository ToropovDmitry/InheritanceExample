// InheritanceExample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>

class creature
{
private:
	std::string title;
	double mass;
protected:
	creature() : mass(0.0) {}
	creature(const creature& obj) : title(obj.title), mass(obj.mass) {}
	creature(const std::string& _title, double _mass) : title(_title), mass(_mass) {}	
	virtual ~creature() { std::cout << "creature deleted" << std::endl << std::endl; }	
	virtual void _print() const { std::cout << "title: " << title << ", mass: " << mass; }	
public:
	void print() const
	{
		std::cout << typeid(*this).name() << ": (";		
		_print();
		std::cout << ")" << std::endl;
	}
	double get_mass() const 
	{
		return mass;
	}
};

class animal : public creature
{
private:
	double speed;
public:
	animal() : creature() {}
	animal(const animal& obj) : creature(obj), speed(obj.speed) {}
	animal(const std::string& _title, double _mass, double _speed)
		: creature(_title, _mass), speed(_speed) {}
	~animal() { std::cout << "animal deleted" << std::endl; }
	double get_speed() const
	{
		return speed;
	}
protected:	
	void _print() const
	{
		creature::_print();
		std::cout << ", speed: " << speed;
	}
	
};

class bird : virtual public animal
{
private:
	double topfly; 
public:
	bird() : animal() {}
	bird(const bird& obj) : animal(obj), topfly(obj.topfly) {}
	bird(const std::string& _title, double _mass, double _speed, double _topfly)
		: animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() { std::cout << "bird deleted" << std::endl; }
protected:
	void _print() const
	{
		animal::_print();
		std::cout << ", topfly: " << topfly;
	}
};

class fish : public animal
{
private:
	double maxdeep;
public:
	fish() : animal() {}
	fish(const fish& obj) : animal(obj), maxdeep(obj.maxdeep) {}
	fish(const std::string& _title, double _mass, double _speed, double _maxdeep)
		: animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish() { std::cout << "fish deleted" << std::endl; }
protected:	
	void _print() const
	{
		animal::_print();
		std::cout << ", maxdeep: " << maxdeep;
	}
};

class predator : virtual public animal 
{
protected:
	predator() {}
public:
	~predator() {}
	virtual bool hunt(const animal& obj) = 0;
};

class eagle : public bird, public predator 
{
public:
	eagle() : bird() {}
	eagle(const eagle& obj) 
		: bird(obj),
		animal(obj) {}
	eagle(double _mass, double _speed, double _topfly)
		: bird("", 0, 0, _topfly),
		animal("Орёл", _mass, _speed) {}
	bool hunt(const animal& obj)
	{
		return obj.get_mass() < bird::get_mass() && obj.get_speed() < bird::get_speed();
	}
};

int main()
{
	setlocale(0, "Rus");
	bird raven("Ворона", 0.3, 10, 0.1);
	eagle eagle(1, 100, 1);
	fish hammerhead("Рыба-молот", 150, 5, 0.5);
	raven.print();
	hammerhead.print();
	std::cout << "Eagle vs raven: " << eagle.hunt(raven) << std::endl;
	std::cout << "Eagle vs hammerhead: " << eagle.hunt(hammerhead) << std::endl;
	std::cout << std::endl;
	return 0;
}

