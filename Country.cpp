//
//  Country.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Country.h"

using namespace std;

Country::Country()
{
	setCountry("USA");
	setNumOfAreas(0);
	setNumOfCitiesPerArea(0);


}
Country::Country(string ctry, int numOfAreas, int numOfCitiesPerArea)
{
	setCountry(ctry);
	setNumOfAreas(numOfAreas);
	setNumOfCitiesPerArea(numOfCitiesPerArea);
}

// Destructor
Country::~Country()
{

}


// SETTERS
 void Country::setCountry(string ctry)
 {
	 country = ctry;
 }

 void Country::setNumOfAreas(int numOfAreas)
 {
	 numberOfAreas = numOfAreas;
 }

 void Country::setNumOfCitiesPerArea(int numOfCitiesPerArea)
 {
	 NumberOfCitiesPerArea = numOfCitiesPerArea;
 }

 // GETTERS

  string Country::Country::getCountry()
  {
	  return country;
   }

 int Country::getNumOfArea()
 {
	 return numberOfAreas;
 }

int Country::getNumOfCitiesPerArea()
{
	return NumberOfCitiesPerArea;
}


