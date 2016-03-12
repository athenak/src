//
//  Houses.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-18.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Houses.h"

using namespace std;

// default constructor
Houses::Houses()
{
	setPlayerID(0);
	setHouseColor("");
	setNumberOfHouses(0);
	setPlacementSpaceInCities(0);
}

// constructor
Houses::Houses(int playerID, string colorHouse, int numOfHouses,int placementSpaceInCities)
{
    setPlayerID(playerID);
    setHouseColor(colorHouse);
    setNumberOfHouses(numOfHouses);
    setPlacementSpaceInCities(placementSpaceInCities);
}

Houses::~Houses()  //Destructor
{

}

// GETTERS
int Houses::getPlayerID()
{
    return playerID;
}

string Houses::getHouseColor()
{
    return colorHouse;
}

int Houses::getNumberOfHouses()
{
    return numberOfHouses;
}

int Houses::getPlacementSpaceInCities()
{
	return placementSpaceInCities;
}

// SETTERS

void Houses::setPlayerID(int playID)
{
    playerID = playID;
}

void Houses::setHouseColor(string col)
{
    colorHouse = col;
}

void Houses::setNumberOfHouses(int house)
{
    numberOfHouses = house;
}

void Houses::setPlacementSpaceInCities(int placementSpaceInCities)
{
	this->placementSpaceInCities = placementSpaceInCities;
}


