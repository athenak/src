//
//  Uranium.h
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Uranium_h
#define Uranium_h

#include <stdio.h>
#include <iostream>
#include<string>
#include "Resources.h"

using namespace std;

class Uranium: public Resources
{
public:
    Uranium();

    Uranium(int totalNumUranium, int numOfUranium, int priceOfUranium);

    ~Uranium();  // Destructor

    int getTotalNumUranium();

    int getNumOfUranium();

    int getPriceOfUranium();

    void setTotalNumUranium(int totalNumUranium);

    void setNumOfUranium(int numOfUranium);

    void setPriceOfUranium(int priceOfUranium);

    void displayMessage();

private:
    int totalNumUranium;
    int numOfUranium;
    int priceOfUranium;

};

#endif /* Uranium_h */
