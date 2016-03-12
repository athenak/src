//
//  Coal.h
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Coal_h
#define Coal_h

#include <stdio.h>
#include <iostream>
#include<string>
#include "Resources.h"

using namespace std;

class Coal: public Resources
{
public:
    Coal();

    Coal(int totalNumCoalOnSpace, int numOfSpace, int priceOfCoal);
    ~Coal();  // Destructor

    int getTotalNumCoalOnSpace();

    int getNumOfSpace();

    int getPriceOfCoal();

    void setTotalNumCoalOnSpace(int totalNumCoalOnSpace);

    void setNumOfSpace(int numOfSpace);

    void setPriceOfCoal(int priceOfCoal);

    void displayMessage();


private:
    int totalNumCoalOnSpace;
    int numOfSpace;
    int priceOfCoal;

};

#endif /* Coal_h */
