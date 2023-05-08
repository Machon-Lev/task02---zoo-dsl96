
#include "Zoo.h"
#include<iostream>

using  namespace std;


Zoo::Zoo()
{
	srand(time(0));
	this->init();
	this->printZoo();
}


void Zoo::addAnimal(Animal* const animal)
{
	this->animals.push_back( animal);
}

void Zoo::init()
{
	Lion* const lion = new Lion("Mufasa", Util::GetRandomLocation());
	Owl* const owl = new Owl("Saun", Util::GetRandomLocation());
	Dog* const dog = new Dog("Toto", Util::GetRandomLocation());

	this->addAnimal(lion);
	this->addAnimal(owl);
	this->addAnimal(dog);
}

void Zoo::stepAll()
{
	for (Animal* animal : this->animals)
		animal->step();

}

void Zoo::printZoo()
{
	char zooMatrix[ZooConfig::hight][ZooConfig::Width];

	//fill zoo matrix with empty
	for (int i = 0; i < ZooConfig::hight; ++i)
		for (int j = 0; j < ZooConfig::Width; ++j)
			zooMatrix[i][j] = ' ';

	//fill animals in matrix
	Location animalLoc;
	for (Animal* const animal : this->animals)
	{
		animalLoc = animal->getLoc();

		zooMatrix[animalLoc.row][animalLoc.col] = animal->GetInitial();
	}

	//print zoo matrix
	for (int row = 0; row < ZooConfig::hight; ++row)
	{
		cout << endl;
		for (int coll = 0; coll < ZooConfig::Width; ++coll)
			cout << "[" << zooMatrix[row][coll] << "]";
	}


	cout << endl;
	//print list 
	for (int i = 0; i < this->animals.size(); ++i)
		cout << i << ':' << animals[i]->printDiteals() << endl;
	cout << endl;
}

enum OPTIONS { STOP = 1, MOVE, CREATE, DELL, DELL_ALL, HELP, EXIT, DOT };

void Zoo::help()
{
	cout << "1 STOP \n2 MOVE \n3 CREATE \n4 DELL \n5 DELL_ALL \n6 HELP \n7 EXIT \n8 DOT \n";
}

OPTIONS getInput()
{
	int opt;
	while (true)
	{
		cin >> opt;
		if (1 <= opt && opt <= 8)
			return (OPTIONS)opt;

		// Clear the input stream
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int getIntFromUser(string msg)
{
	cout << msg << endl;
	int num;
	cin >> num;
	return num;
}

void Zoo::stopByIndex(int index)
{
	if (index >= this->animals.size())
	{
		cout << "out of range";
		return;
	}
		

	this->animals[index]->stop();
}

void Zoo::moveByIndex(int index)
{
	if (index >= this->animals.size())
	{
		cout << "out of range";
		return;
	}

	this->animals[index]->move();
}

void Zoo::deleteByIndex(int index)
{
	if (index >= this->animals.size())
	{
		cout << "out of range";
		return;
	}

	delete this->animals[index];
	this->animals.erase(this->animals.begin() + index);
}

void Zoo::deleteAllAnimals()
{
	for (Animal* animal : this->animals)
	{
		delete animal;
	}
	this->animals.clear();
}

void Zoo::createAnimal()
{
	int choise;
	string name;
	Location loc = Util::GetRandomLocation();

	cout << "Choose an animal:\n1 LION\n2 OWL\n3 DOG\n";
	cin >> choise;
	cout << "Enter name\n";
	cin >> name;

	switch (choise)
	{
	case 1:
		this->addAnimal(new Lion(name, loc));
		break;
	case 2:
		this->addAnimal(new Owl(name, loc));
		break;
	case 3:
		this->addAnimal(new Dog(name, loc));
		break;
	default:
		cout << "Bad choise" << endl;
	}

}


void Zoo::run()
{
	OPTIONS chois;

	this->help();

	while (true)
	{
		chois = getInput();

		switch (chois)
		{
		case STOP:
			this->stopByIndex(getIntFromUser("enter index to stop"));
			break;
		case MOVE:
			this->moveByIndex(getIntFromUser("enter index to move"));
			break;
		case CREATE:
			this->createAnimal();
			break;
		case DELL:
			this->deleteByIndex(getIntFromUser("enter index to delete"));
			break;
		case DELL_ALL:
			this->deleteAllAnimals();
			break;
		case HELP:
			this->help();
			break;
		case EXIT:
			return;
			break;
		case DOT:
			break;
		default:
			break;
		}
		this->stepAll();
		this->printZoo();
	}
}