//
//  PowerPlant.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-18.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "PowerPlant.h"

using namespace std;

// default constructor
PowerPlant::PowerPlant()
{

}


// constructor
PowerPlant::PowerPlant(int mBid, int mResToProdPow, int storeAmtRes,string resTyp, int howManyCities, bool isHyb, bool isEcoOrFus)
{
    setMinBid(mBid);
    setMinResToProdPow(mResToProdPow);
    setStoreAmountRes(storeAmtRes);
    setResType(resTyp);
    setHowManyCitiesCanPower(howManyCities);
    setIsHybrid(isHyb);
    setIsEcolOrFusion(isEcoOrFus);
}
// Getters
int PowerPlant::getMinBid()
{
    return minBid;
}

int PowerPlant::getMinResToProdPow()
{
    return minResToProdPow;
}

int PowerPlant::getStoreAmountRes()
{
    return storeAmountRes;
}

string PowerPlant::getResType()
{
    return resType;
}

int PowerPlant::getHowManyCitiesCanPower()
{
    return howManyCitiesCanPower;
}

bool PowerPlant::getIsHybrid()
{
    return isHybrid;
}

bool PowerPlant::getIsEcolOrFusion()
{
    return isEcolOrFusion;
}
void PowerPlant::setNumberPowerPlants(int powerPlants){
	numberPowerPlants += powerPlants;
}

// Setters
void PowerPlant::setMinBid(int bid)
{
    minBid = bid;
}

void PowerPlant::setMinResToProdPow(int minRes)
{
    minResToProdPow = minRes;
}

void PowerPlant::setStoreAmountRes(int storeAmount)
{
    storeAmountRes = storeAmount;
}

void PowerPlant::setResType(string resTyp)
{
    resType = resTyp;
}

void PowerPlant::setHowManyCitiesCanPower(int howManyCity)
{
    howManyCitiesCanPower = howManyCity;
}

void PowerPlant::setIsHybrid(bool isHyb)
{
    isHybrid = isHyb;
}

void PowerPlant::setIsEcolOrFusion(bool isEcoOrFus)
{
    isEcolOrFusion = isEcoOrFus;
}

// function to display Power Plant parameters and information
void PowerPlant::displayMessage(){
	cout << "Power Plant Number for bidding: "<< getMinBid()<<endl;
    cout << "The minimum bid for this Power Plant is " << getMinBid() << endl;
    cout << "The minimum number of resources needed to produce power for this Power Plant is " << getMinResToProdPow() << endl;
    cout << "The maximum amount of resources that can be stored in this plant is " << getStoreAmountRes() << ". " << endl << "This power plant uses " <<  getResType() << " to run. " << endl;
    cout << "It can power " << getHowManyCitiesCanPower() << " number of cities." << endl << endl;
}

PowerPlant::~PowerPlant()  // Destructor
{

}
