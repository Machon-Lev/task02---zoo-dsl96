

#include "Owl.h"
#include "Animal.h"

void Owl::step() {

	if (Animal::getIsStop())
		return;

	Location newLoc = Animal::getLoc();
	newLoc += nextMove();

	if (Animal::TryChangeLoc(newLoc))
	{
		return;
	}
	else
	{
		Animal::turnHorizontally();
		Animal::turnVertically();
	}

	newLoc = Animal::getLoc();
	newLoc += nextMove();
	Animal::TryChangeLoc(newLoc);
}

Location Owl::nextMove() {

	switch (Animal::getIsRight())
	{
	case true:
		return Animal::getIsUp() ? RightUpMove : RightDownMove;
	case false:
		return Animal::getIsUp() ? LeftUpMove : LeftDownMove;
	}
}


ostream& operator<<(ostream& os, const Owl& owl) {

	os << "OWL " << (Animal&)owl;
	return os;
}