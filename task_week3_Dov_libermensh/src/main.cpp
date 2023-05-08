// ZOO.cpp : Defines the entry point for the application.
//
#include<iostream>
#include "Location.h"
#include "Animal.h"
#include "Lion.h"
#include "Owl.h"
#include "Dog.h"
#include "Zoo.h"

using namespace std;

int main()
{
	srand(time(0));

	//Lion lion = Lion("Mufasa", {29, 0});
	//cout << "Hello " << lion << endl;
	//for (int i = 0; i < 20; i++) {
	//	lion.step();
	//	cout << "After step: " << lion << endl;
	//}


	//Owl owl = Owl("Hedwig", { 20, 10 });
	//cout << "Hello " << owl << endl;
	//for (int i = 0; i < 20; i++) {
	//	owl.step();
	//	cout << "After step: " << owl << endl;
	//}

	/*Dog dog = Dog("Toto", { 20, 10 });
	cout << "Hello " << dog << endl;
	for (int i = 0; i < 20; i++) {
		dog.step();
		cout << "After step: " << dog << endl;
	}*/

	auto zoo = Zoo();
	 zoo.run();

	return 0;
}
