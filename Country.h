//
//  Country.h
//  Power Grid
//
//  Created by Athena on 2016-02-16.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Country_h
#define Country_h

#include <stdio.h>
#include <iostream>
#include<string>


using namespace std;

// Country class definition
// Country.h

class Country
{
public:
    Country();
    Country(string ctry, int numOfAreas, int numOfCitiesPerArea);
    ~Country();  //Destructor

    void setCountry(string ctry);

    void setNumOfAreas(int numOfArea);

    void setNumOfCitiesPerArea(int numOfCitiesPerArea);

    string getCountry();

    int getNumOfArea();

    int getNumOfCitiesPerArea();

private:
    string country;
    int numberOfAreas;
    int NumberOfCitiesPerArea;
};

#endif /* Country_h */
