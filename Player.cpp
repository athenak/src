//
//  Player.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-15.
//  Copyright © 2016 Athena. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

// default constructor
Player::Player()
{
	setPlayerName(" ");
}

Player::Player(string playName)
{
    setPlayerName(playName);
}

// constructor
Player::Player(int playID, string playName, string playColor, int numOfHouses,int electros,string powerCompanyNme)
{
    setPlayerID(playID);
    setPlayerName(playName);
    setPlayerColor(playColor);
    setPowerCompanyName(powerCompanyNme);
	setPlayerNumberOfHouses(numOfHouses);
	setPlayerElectros(electros);
}

Player::~Player()  // Destructor
{

}


//Getters
int Player::getPlayerID()
{
    return playerID;
}

string Player::getPlayerName()
{
    return playerName;
}

string Player::getPlayerColor()
{
    return playerColor;
}

int Player::getPlayerElectros()
{
    return playerElectros;  //???
}

int Player::getPlayerNumberOfHouses()
{
    return playerNumberOfHouses;  ///???
}

string Player::getPowerCompanyName()
{
    return powerCompanyName;
}

int Player::getPlayerNumberAreaOnMap()
{
    return playerTurn;  ///???
}

int Player::getPlayerTurn()
{
    return playerTurn;  ///???
}

int Player::getPlayerNumberOfPowerPlants(){
	return playerNumberOfPowerPlants;
}

// Setters

void Player::setPlayerID(int ID)
{
    playerID = ID;
}

void Player::setPlayerName(string name)
{
    playerName = name;
}

void Player::setPlayerColor(string color)
{
    playerColor = color;
}

void Player::setPlayerElectros(int electros)
{
    playerElectros = electros;
}

void Player::setPlayerNumberOfHouses(int house)
{
    playerNumberOfHouses = house;
}

void Player::setPowerCompanyName(string companyNme)
{
    powerCompanyName = companyNme;
}

void Player::setPlayerNumberAreaOnMap(int mapAreaNumber)
{
    playerNumberAreaOnMap = mapAreaNumber;
}

void Player::setPlayerTurn(int turn)
{
     playerTurn = turn;
}

void Player::setPlayerNumberOfPowerPlants(int powerPlant){
	playerNumberOfPowerPlants += powerPlant;
}


// function to display player parameters set
void Player::displayMessage(){
    cout << "The name of the player is  " << getPlayerName() << endl;
    cout << "The name of the Company is  " << getPowerCompanyName() << endl;
    cout << "The player has "<<getPlayerNumberOfHouses()<<" houses to start and "<<getPlayerElectros()<<" Elektros.\nThe color of the houses chosen by this player is " <<  getPlayerColor() << endl;
    cout << "One of each player's house is placed on the start house (representing 0) in the scoring track." << endl;
}


