//
//  Garbage.h
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Garbage_h
#define Garbage_h

#include <stdio.h>
#include <iostream>
#include<string>
#include "Resources.h"

using namespace std;

class Garbage: public Resources
{
public:
	Garbage();

    Garbage(int totalNumGarbageOnSpace, int numOfSpace, int priceOfGarbage);

    ~Garbage();   //Destructor

    int getTotalNumGarbageOnSpace();

    int getNumOfSpace();

    int getPriceOfGarbage();

    void setTotalNumGarbageOnSpace(int totalNumGarbageOnSpace);

    void setNumOfSpace(int numOfSpace);

    void setPriceOfGarbage(int priceOfGarbage);

    void displayMessage();

private:
    int totalNumGarbageOnSpace;
    int numOfSpace;
    int priceOfGarbage;
};

#endif /* Garbage_h */
