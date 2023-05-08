#pragma once
#include "Location.h"
#include <iostream>
#include <string>

using std::string;


class Animal {

	string name;
	Location loc;
	bool isStop;
	bool isUp;
	bool isRight;

 protected:
	bool TryChangeLoc(Location newLoc);
	virtual void turnVertically() { isUp = !isUp; }
	virtual void turnHorizontally() { isRight = !isRight; }

  public:
	bool getIsStop() const { return isStop; }
	bool getIsUp() { return isUp; }
	bool getIsRight() { return isRight; }
	Location getLoc() { return loc; }

	Animal(string name, Location loc);

	virtual void move() { isStop = false; }
	void stop() { isStop = true; }

	virtual void step() =  0;

	virtual char GetInitial() = 0;

	virtual string printDiteals()
	{
		return " name: " +this->name + " coll: " + std::to_string(this->loc.col) + " row: " + std::to_string(this->loc.row ) ;
	}

	friend ostream& operator<<( ostream& os, const Animal& animal);	
};