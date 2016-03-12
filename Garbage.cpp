//
//  Garbage.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include<string>
#include "Garbage.h"
#include "Resources.h"

using namespace std;

// default constructor
Garbage::Garbage()
{
	setTotalNumGarbageOnSpace(0);
	 setNumOfSpace(0);
	 setPriceOfGarbage(0);
}

// constructor
Garbage::Garbage(int totalNumGarbageOnSpace, int numOfSpace, int priceOfGarbage)
{
    //setResColor(color);
    setTotalNumGarbageOnSpace(totalNumGarbageOnSpace);
    setNumOfSpace(numOfSpace);
    setPriceOfGarbage(priceOfGarbage);
}

Garbage::~Garbage()   //Destructor
{

}

// getters
int Garbage::getTotalNumGarbageOnSpace()
{
    return totalNumGarbageOnSpace;
}

int Garbage::getNumOfSpace()
{
    return numOfSpace;
}

int Garbage::getPriceOfGarbage()
{
    return priceOfGarbage;
}


// setters
void Garbage::setTotalNumGarbageOnSpace(int totalNumGarbageOnSpace)
{
    this->totalNumGarbageOnSpace = totalNumGarbageOnSpace;
}

void Garbage::setNumOfSpace(int numOfSpace)
{
    this->numOfSpace = numOfSpace;
}

void Garbage::setPriceOfGarbage(int priceOfGarbage)
{
    this->priceOfGarbage = priceOfGarbage;
}

void Garbage::displayMessage()
{
    cout << "\nThere is a garbage resource on space: " << getNumOfSpace();
    cout << "\nThe price of this garbage resource is $" << getPriceOfGarbage() << " Elektros." << endl;
}



