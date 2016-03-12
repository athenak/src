//
//  Oil.h
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Oil_h
#define Oil_h

#include <stdio.h>
#include <iostream>
#include<string>
#include "Resources.h"

using namespace std;

class Oil: public Resources
{
public:
    Oil();

    Oil(int totalNumOilOnSpace, int numOfSpace, int priceOfOil);

    ~Oil();  // Destructor

    int getTotalNumOilOnSpace();

    int getNumOfSpace();

    int getPriceOfOil();

    void setTotalNumOilOnSpace(int totalNumOilOnSpace);

    void setNumOfSpace(int numOfSpace);

    void setPriceOfOil(int priceOfOil);

    void displayMessage();

private:
    int totalNumOilOnSpace;
    int numOfSpace;
    int priceOfOil;

};

#endif /* Oil_h */
