#pragma once


#include "Location.h"
#include "Util.h"
#include"Animal.h"

class Owl : public Animal {

	const Location RightUpMove = { 3, 3 };
	const Location RightDownMove = { 3, -3 };
	const Location LeftUpMove = { -3, 3 };
	const Location LeftDownMove = { -3, -3 };

	Location nextMove();

public:

	Owl(string name, Location loc) :Animal(name, loc) {

	}

	void step() override;

	friend ostream& operator<<(ostream& os, const Owl& owl);

	char GetInitial() override
	{
		return 'O';
	}

	string printDiteals()
	{
		return  "OWL: " + Animal::printDiteals();
	}
};