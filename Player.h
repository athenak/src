//
//  Player.h
//  Power Grid
//
//  Created by Athena on 2016-02-15.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <iostream>
#include<string>
#include"Cities.h"
#include"PowerPlant.h"
#include"Payments.h"
#include"PlayerOrder.h"
#include"Houses.h"
#include"Money.h"

using namespace std;

class Player: public Cities, public PowerPlant, public Payments, public Houses, public Money, public PlayerOrder
{
public:
    Player();

    Player(string playName);

    Player(int playID, string playName, string playColor, int numOfHouses,int electros,string powerCompanyNme);

    ~Player();  // Destructor

    int getPlayerID();

    string getPlayerName();

    string getPlayerColor();

    int getPlayerElectros();

    int getPlayerNumberOfHouses();

    string getPowerCompanyName();

    int getPlayerNumberAreaOnMap();

    int getPlayerNumberOfPowerPlants();

    int getPlayerTurn();


    void setPlayerID(int ID);

    void setPlayerName(string name);

    void setPlayerColor(string color);

    void setPlayerElectros(int electros);

    void setPlayerNumberOfHouses(int house);

    void setPowerCompanyName(string companyNme);

    void setPlayerNumberAreaOnMap(int mapAreaNumber);

    void setPlayerTurn(int turn);

    void setPlayerNumberOfPowerPlants(int powerPlant);

    void displayMessage();

private:
    int playerID;
    string playerName;
    string playerColor;
    int playerElectros;
    int playerNumberOfHouses;
    string powerCompanyName;
    int playerNumberAreaOnMap;
    int playerTurn;
    int playerNumberOfPowerPlants;
    Cities Cities;
    PowerPlant powerPlants;
	Payments payments;
	PlayerOrder playerOrder;
};

#endif /* Player_h */
