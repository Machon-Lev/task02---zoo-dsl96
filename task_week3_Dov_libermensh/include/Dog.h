#pragma once

#include "Location.h"
#include "Util.h"
#include "Animal.h"




class Dog :public Animal {

	const Location rightMove = { 3, 0 };
	const Location LeftMove = { -3, 0 };
	const Location upMove = { 0, 3 };
	const Location downMove = { 0, -3 };

	const Location backRightMove = { -1, 0 };
	const Location backLeftMove = { 1, 0 };
	const Location backUpMove = { 0, -1 };
	const Location backDownMove = { 0, 1 };

	bool isForwardStep;
	bool isMoveHorizontally;

	Location getNextLocation();

public:

	Dog(string name, Location loc);

	void step() override;

	void move();

	friend ostream& operator<<(ostream& os, const Dog& dog);

	char GetInitial() override
	{
		return 'D';
	}

	string printDiteals()
	{
		return  "DOG: " + Animal::printDiteals();
	}

};
