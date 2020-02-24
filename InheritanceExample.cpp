// InheritanceExample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <clocale>

class ComputerGameObject
{
protected:
	std::string name;	
	int mana;	
	int x;
	int y;
public:
	virtual void draw() = 0;
};

class Creature : public ComputerGameObject
{
protected:
	int health;
	int stamina;
public:
	virtual void move(int dx, int dy) = 0;
};

class MythologicalAnimal : public Creature
{
public:
	MythologicalAnimal() 
	{
		this->name = "Мифическое животное";
		this->health = 100;
		this->mana = 100;
		this->stamina = 100;
		this->x = 0;
		this->y = 0;
	}
	MythologicalAnimal(const MythologicalAnimal& mythologicalAnimal) 
	{
		this->name = mythologicalAnimal.name;
		this->health = mythologicalAnimal.health;
		this->mana = mythologicalAnimal.mana;
		this->stamina = mythologicalAnimal.stamina;
		this->x = mythologicalAnimal.x;
		this->y = mythologicalAnimal.y;
	}
	MythologicalAnimal(std::string name, int heath, int mana, int stamina, int x, int y)
	{
		this->name = name;
		this->health = heath;
		this->mana = mana;
		this->stamina = stamina;
		this->x = x;
		this->y = y;
	}
	void move(int dx, int dy)
	{
		this->x += dx;
		this->y += dy;
		if (dx != 0 || dy != 0)
			std::cout << this->name << " движется в точку с координатами (" << this->x << ";" << this->y << ")" << std::endl;
		else
			std::cout << this->name << " стоит на месте, не обращая на вас внимания" << std::endl;
	}
	void draw()
	{
		std::cout << this->name << " стоит в точке с координатами (" << this->x << ";" << this->y << ")" << std::endl;
	}
	~MythologicalAnimal() {}
};

class Human : public Creature
{
public:
	Human()
	{
		this->name = "Человек";
		this->health = 100;
		this->mana = 0;
		this->stamina = 100;
		this->x = 0;
		this->y = 0;
	}
	Human(const Human& human)
	{
		this->name = human.name;
		this->health = human.health;
		this->mana = human.mana;
		this->stamina = human.stamina;
		this->x = human.x;
		this->y = human.y;
	}
	Human(std::string name, int heath, int mana, int stamina, int x, int y)
	{
		this->name = name;
		this->health = heath;
		this->mana = mana;
		this->stamina = stamina;
		this->x = x;
		this->y = y;
	}
	void move(int dx, int dy)
	{
		this->x += dx;
		this->y += dy;
		if (dx != 0 || dy != 0)
			std::cout << this->name << " движется в точку с координатами (" << this->x << ";" << this->y << ")" << std::endl;
		else
			std::cout << this->name << " стоит на месте, не обращая на вас внимания" << std::endl;
	}
	void draw()
	{
		std::cout << this->name << " стоит в точке с координатами (" << this->x << ";" << this->y << ")" << std::endl;
	}
	~Human() {}
};

class MagicPerson : public Creature
{
public:
	MagicPerson()
	{
		this->name = "Волшебное создание";
		this->health = 100;
		this->mana = 100;
		this->stamina = 100;
		this->x = 0;
		this->y = 0;
	}
	MagicPerson(const MagicPerson& magicPerson)
	{
		this->name = magicPerson.name;
		this->health = magicPerson.health;
		this->mana = magicPerson.mana;
		this->stamina = magicPerson.stamina;
		this->x = magicPerson.x;
		this->y = magicPerson.y;
	}
	MagicPerson(std::string name, int heath, int mana, int stamina, int x, int y)
	{
		this->name = name;
		this->health = heath;
		this->mana = mana;
		this->stamina = stamina;
		this->x = x;
		this->y = y;
	}
	void move(int dx, int dy)
	{
		this->x += dx;
		this->y += dy;
		if (dx != 0 || dy != 0)
			std::cout << this->name << " движется в точку с координатами (" << this->x << ";" << this->y << ")" << std::endl;
		else
			std::cout << this->name << " стоит на месте, не обращая на вас внимания" << std::endl;
	}
	void draw()
	{
		std::cout << this->name << " стоит в точке с координатами (" << this->x << ";" << this->y << ")" << std::endl;
	}
	~MagicPerson() {}
};

class MagicThing : public ComputerGameObject
{
public:
	MagicThing()
	{
		this->name = "Волшебный предмет";		
		this->mana = 100;		
		this->x = 0;
		this->y = 0;
	}
	MagicThing(const MagicThing& magicThing)
	{
		this->name = magicThing.name;		
		this->mana = magicThing.mana;		
		this->x = magicThing.x;
		this->y = magicThing.y;
	}
	MagicThing(std::string name, int mana, int x, int y)
	{
		this->name = name;		
		this->mana = mana;		
		this->x = x;
		this->y = y;
	}	
	void draw()
	{
		std::cout << this->name << " находиться в точке с координатами (" << this->x << ";" << this->y << ")" << std::endl;
	}
	~MagicThing() {}
};

int main()
{
	setlocale(0, "Rus");
	MythologicalAnimal pegasus = MythologicalAnimal("Пегас", 100, 100, 100, 5, 10);
	Human perseus = Human("Персей", 100, 50, 100, 5, 10);
	MagicPerson gorgon = MagicPerson("Медуза Горгона", 100, 100, 100, -11, 0);
	MagicThing teardrop = MagicThing("Слеза Богов", 1000, -30, -30);
	teardrop.draw();
	pegasus.draw();
	perseus.draw();
	gorgon.draw();
	pegasus.move(-10, 0);
	perseus.move(-10, 0);
	gorgon.move(-2, -5);
	pegasus.draw();
	perseus.draw();
	gorgon.draw();
	std::cout << std::endl;
	return 0;
}

