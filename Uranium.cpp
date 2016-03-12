//
//  Uranium.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Uranium.h"
#include "Resources.h"

using namespace std;

    // default constructor
    Uranium::Uranium()
    {
    	// setResColor(color);
    	setTotalNumUranium(0);
    	setNumOfUranium(0);
    	setPriceOfUranium(0);
    }

    // constructor
    Uranium::Uranium(int totalNumUranium, int numOfUranium, int priceOfUranium)
    {
       // setResColor(color);
        setTotalNumUranium(totalNumUranium);
        setNumOfUranium(numOfUranium);
        setPriceOfUranium(priceOfUranium);
    }

    Uranium::~Uranium()  // Destructor
    {

    }

    // GETTERS
    int Uranium::getTotalNumUranium()
    {
        return totalNumUranium;
    }

    int Uranium::getNumOfUranium()
    {
        return numOfUranium;
    }

    int Uranium::getPriceOfUranium()
    {
        return priceOfUranium;
    }

    // SETTERS
    void Uranium::setTotalNumUranium(int totalNumUranium)
    {
        this->totalNumUranium = totalNumUranium;
    }

    void Uranium::setNumOfUranium(int numOfUranium)
    {
        this->numOfUranium = numOfUranium;
    }

    void Uranium::setPriceOfUranium(int priceOfUranium)
    {
        this->priceOfUranium = priceOfUranium;
    }

    void Uranium::displayMessage()
    {
        cout << "Uranium Reource";
    }


