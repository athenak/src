//
//  Resources.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Resources.h"

using namespace std;

// default constructor
Resources::Resources()
{
	 resColor = " ";
}

// constructor
Resources::Resources(string color)
{
    resColor = color;
}

Resources::~Resources()  // Destructor
{

}

// getters , get color of resource
string Resources::getResColor()
{
    return resColor;
}

// setters, set color of resource
void Resources::setResColor(string color)
{
    resColor = color;
}

// display type of resource object to console
void Resources::displayMessage()
{
    cout << "Resources Object";
}



