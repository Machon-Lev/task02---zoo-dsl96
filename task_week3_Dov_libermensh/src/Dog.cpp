#include "Dog.h"
#include "Animal.h"




Dog::Dog(string name, Location loc) :Animal(name, loc) {

	isForwardStep = true;
	isMoveHorizontally = Util::GetRandBool();
}

void Dog::step() {

	if (Animal::getIsStop())
		return;

	Location newLoc = getNextLocation();

	if (!Animal::TryChangeLoc(newLoc))
	{
		Animal::turnHorizontally();
		Animal::turnVertically();

		newLoc = getNextLocation();
		Animal::TryChangeLoc(newLoc);
	}
	this->isForwardStep = !this->isForwardStep;
}

Location Dog::getNextLocation() {

	Location newLoc = Animal::getLoc();

	if (this->isMoveHorizontally)
		if (this->isForwardStep)
			newLoc += Animal::getIsRight() ? rightMove : LeftMove;
		else
			newLoc += Animal::getIsRight() ? backRightMove : backLeftMove;
	else
		if (this->isForwardStep)
			newLoc += Animal::getIsUp() ? upMove : downMove;
		else
			newLoc += Animal::getIsUp() ? backUpMove : backDownMove;
	return newLoc;
}

void Dog::move() {
	this->isMoveHorizontally = Util::GetRandBool();
	Animal::move();
}

ostream& operator<<(ostream& os, const Dog& dog) {

	os << "DOG " << (Animal&)dog;
	return os;
}