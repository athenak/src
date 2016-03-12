//
//  Oil.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include<string>
#include "Oil.h"
#include "Resources.h"

using namespace std;

// default constructor
Oil::Oil()
{
	// setResColor(color);
	    setTotalNumOilOnSpace(0);
	    setNumOfSpace(0);
	    setPriceOfOil(0);
}

// constructor
Oil::Oil(int totalNumOilOnSpace, int numOfSpace, int priceOfOil)
{
   // setResColor(color);
    setTotalNumOilOnSpace(totalNumOilOnSpace);
    setNumOfSpace(numOfSpace);
    setPriceOfOil(priceOfOil);
}

Oil::~Oil()  // Destructor
{

}

// getters
int Oil::getTotalNumOilOnSpace()
{
    return totalNumOilOnSpace;
}

int Oil::getNumOfSpace()
{
    return numOfSpace;
}

int Oil::getPriceOfOil()
{
    return priceOfOil;
}


// setters
void Oil::setTotalNumOilOnSpace(int totalNumOilOnSpace)
{
    this->totalNumOilOnSpace = totalNumOilOnSpace;
}

void Oil::setNumOfSpace(int numOfSpace)
{
    this->numOfSpace = numOfSpace;
}

void Oil::setPriceOfOil(int priceOfOil)
{
    this->priceOfOil = priceOfOil;
}

void Oil::displayMessage()
{
    cout << "\nThere is an oil resource on space: " << getNumOfSpace();
    cout << "\nThe price of this oil resource is $" << getPriceOfOil() << " Elektros." << endl;
}


