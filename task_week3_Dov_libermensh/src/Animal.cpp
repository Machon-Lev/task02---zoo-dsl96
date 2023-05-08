#include "Animal.h"
#include"Util.h"



 

Animal::Animal(string name, Location loc) {
	this->loc = loc;

	 //TODO add func rand bool in utils
	this->isRight = Util::GetRandBool();
	this->isUp = Util::GetRandBool();

	this->isStop = false;
	this->name = name;
 }



 bool Animal:: TryChangeLoc(Location newLoc) {
	if (Util::CheckValidLocation(newLoc)) {
		loc = newLoc;
		return true;
	}
	return false;
}

 std::ostream& operator<<( std::ostream& os, const Animal& animal) {

	 os << "name:" << animal.name << animal.loc << std::endl;
	 return os;
}
 
