//
//  GamePlay.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-07.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "GamePlay.h"

using namespace std;

// default constructor
GamePlay::GamePlay()
{
	setCountry(1);
	setNumOfPlayers(2);
	electros = 50; // default # of electros to start is 50 for every player
	color = "";
}

// constructor initialize GamePlay with string supplied as argument
GamePlay::GamePlay(int ctry, int numPlayers)
{
    setCountry(ctry);
    setNumOfPlayers(numPlayers);
    electros = 50; // default # of electros to start is 50 for every player
    color = "";

}

GamePlay::~GamePlay()  //Destructor
{

}

//function to set the country
void GamePlay::setCountry(int ctry)
{
    country = ctry;  //store the country name in the object
}

//function to set the number of players
void GamePlay::setNumOfPlayers(int playerNumb)
{
    numOfPlayers = playerNumb;  //store the number of players in the object
}

// function to set the amount of electros
void GamePlay::setElectros(int money)
{
    electros = money;
}

//function to set the color for the user
void GamePlay::setColor(string col)
{
    color = col;
}

//function to get the country
int GamePlay::getCountry()
{
    return country;  // return object country
}

//function to get the number of players
int GamePlay::getNumOfPlayers()
{
    return numOfPlayers;
}

//function to get the number of electros
int GamePlay::getNumberOfElectros()
{
    return electros;
}

//function to get the color of the player
string GamePlay::getColor()
{
    return color;
}

// function to display game parameters set
void GamePlay::displayMessage(){
    string countryN;

    if(getCountry() == 1)
        countryN = "Not yet Available";
    else
        countryN = "USA";

    cout << "\n\nThe country selected for this game is " << countryN <<  " and the number of players for this game is " << getNumOfPlayers() << ". " << endl;
}


