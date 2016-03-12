//
//  Houses.h
//  Power Grid
//
//  Created by Athena on 2016-02-18.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Houses_h
#define Houses_h

#include <stdio.h>
#include <iostream>
#include<string>

using namespace std;

// Houses class definition
// Houses.h

class Houses
{
public:
    Houses();
    Houses(int playerID, string colorHouse, int numOfHouses, int placementSpaceInCities);
    ~Houses();  //Destructor

    // Getters
    int getPlayerID();

    string getHouseColor();

    int getNumberOfHouses();

    int getPlacementSpaceInCities();

    // Setters
    void setPlayerID(int playID);

    void setHouseColor(string col);

    void setNumberOfHouses(int house);

    void setPlacementSpaceInCities(int placementSpaceInCities);

private:
    int playerID;
    string colorHouse;
    int numberOfHouses;
    int placementSpaceInCities;
};

#endif /* Houses_h */
