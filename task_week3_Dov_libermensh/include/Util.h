#pragma once



#include "Location.h"
#include "ZooConfig.h"
#include <random>


static class Util {

public :

	static bool CheckValidLocation(Location loc){

		return loc.row >= 0 && loc.col >= 0 && loc.col < ZooConfig::Width && loc.row < ZooConfig::hight;
	}


	static bool GetRandBool(){
		return bool(rand() % 2);
	}

	static Location GetRandomLocation() {
		Location loc;
		loc.col = rand() % ZooConfig::Width;
		loc.row = rand() % ZooConfig::hight;
		return loc;
	}

};
