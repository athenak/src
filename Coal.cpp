//
//  Coal.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Coal.h"
#include "Resources.h"


using namespace std;

// default constructor
Coal::Coal()
{
	totalNumCoalOnSpace = 0;
	numOfSpace = 0;
	priceOfCoal = 0;
}

// constructor
Coal::Coal(int totalNumCoalOnSpace, int numOfSpace, int priceOfCoal)
{

    setTotalNumCoalOnSpace(totalNumCoalOnSpace);
    setNumOfSpace(numOfSpace);
    setPriceOfCoal(priceOfCoal);
}

Coal::~Coal()  // Destructor
{

}

// getters
// get total number of coal on spaces (i.e. 3 max per space)
int Coal::getTotalNumCoalOnSpace()
{
    return totalNumCoalOnSpace;
}

// get the number of the space the coal is placed on (i.e. space 2)
int Coal::getNumOfSpace()
{
    return numOfSpace;
}

// get the price of the coal, it should be the same as the space number
int Coal::getPriceOfCoal()
{
    return priceOfCoal;
}

// SETTERS

void Coal::setTotalNumCoalOnSpace(int totalNumCoalOnSpace)
{
    this->totalNumCoalOnSpace = totalNumCoalOnSpace;
}

void Coal::setNumOfSpace(int numOfSpace)
{
    this->numOfSpace = numOfSpace;
}

void Coal::setPriceOfCoal(int priceOfCoal)
{
    this->priceOfCoal = priceOfCoal;
}

void Coal::displayMessage()
{
    cout << "A Coal Resources have been placed on the following space: \n";
    cout << "There is a coal resource on space: " << getNumOfSpace();
    cout << "\nThe price of this coal resource is $" << getPriceOfCoal() << " Elektros.\n" << endl;
}


