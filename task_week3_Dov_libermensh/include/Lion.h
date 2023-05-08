#pragma once


#include "Location.h"
#include "Util.h"
#include "Animal.h"




class Lion :public Animal {

	const Location rightMove = { 2, 0 };
	const Location LeftMove = { -2, 0 };


public:

	 Lion(string name,Location loc):Animal(name,loc) {
       
	 }

	 void step() override;

	 friend ostream& operator<<(ostream& os, const Lion& lion);

	 char GetInitial() override
	 {
		 return 'L';
	 }

	 string printDiteals()
	 {
		 return  "LION: " + Animal::printDiteals();
	 }

 
};




