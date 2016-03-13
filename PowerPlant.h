//
//  PowerPlant.h
//  Power Grid
//
//  Created by Athena on 2016-02-18.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef PowerPlant_h
#define PowerPlant_h

#include <stdio.h>
#include <iostream>
#include<string>

using namespace std;

// PowerPlant class definition
// PowerPlant.h

class PowerPlant
{
public:

    PowerPlant();
    PowerPlant(int mBid, int mResToProdPow, int storeAmtRes,string resTyp, int howManyCities, bool isHyb, bool isEcoOrFus, bool isBought, bool isPowered);
    ~PowerPlant();  // Destructor

    // Getters
    int getMinBid();

    int getMinResToProdPow();

    int getStoreAmountRes();

    string getResType();

    int getHowManyCitiesCanPower();

    bool getIsHybrid();

    bool getIsEcolOrFusion();

    bool getIsBought();

    bool getIsPowered();

    // Setters
    void setMinBid(int bid);

    void setMinResToProdPow(int minRes);

    void setStoreAmountRes(int storeAmount);

    void setResType(string resTyp);

    void setHowManyCitiesCanPower(int howManyCity);

    void setIsHybrid(bool isHyb);

    void setIsEcolOrFusion(bool isEcoOrFus);

    void setIsBought(bool isBought);

    void setIsPowered(bool isPowered);

    void displayMessage();

	void setNumberPowerPlants(int powerPlants);


private:
    int minBid;
    int minResToProdPow;
    int storeAmountRes;
    string resType;
    int howManyCitiesCanPower;
    bool isHybrid;
    bool isEcolOrFusion;
    int numberPowerPlants;
    bool isBought;
    bool isPowered;
};

#endif /* PowerPlant_h */
