#pragma once
#include "Animal.h"

#include "Lion.h"
#include "Dog.h"
#include"Owl.h"

#include<vector>
#include <iostream>
using namespace std;

class Zoo{

private:
	std::vector<Animal*  > animals;
	void init();

	void addAnimal( Animal*   animal);

	void printZoo();

	void help();

	void stepAll();

	void stopByIndex(int index);
	void moveByIndex(int index);
	void deleteByIndex(int index);
	void deleteAllAnimals();
	void createAnimal();



public:

	Zoo();	
	void run();
	 
};

 