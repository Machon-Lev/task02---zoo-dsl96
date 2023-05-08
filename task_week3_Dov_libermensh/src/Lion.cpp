

#include "Lion.h"
#include "Animal.h"



void Lion:: step()   {

	if (Animal::getIsStop())
		return;

	Location newLoc = Animal::getLoc();
	newLoc += Animal::getIsRight() ? rightMove : LeftMove;

	if (Animal::TryChangeLoc(newLoc))
	{
		return;
	}
	else
	{
		Animal::turnHorizontally();
	}

	newLoc = Animal::getLoc();
	newLoc += Animal::getIsRight() ? rightMove : LeftMove;
	Animal::TryChangeLoc(newLoc);
}


ostream& operator<<( ostream& os, const Lion& lion) {

	os << "LION " <<(Animal&) lion;
	return os;
}