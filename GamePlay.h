//
//  GamePlay.h
//  Power Grid
//
//  Created by Athena on 2016-02-07.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef GamePlay_h
#define GamePlay_h

#include <stdio.h>
#include <iostream>
#include<string>
#include "GamePlay.h"

using namespace std;

// GamePlay class definition
// GamePlay.h

class GamePlay {

public:

    GamePlay();
    GamePlay(int ctry, int numPlayers);
    ~GamePlay();  //Destructor

    void setCountry(int ctry);

    void setNumOfPlayers(int playerNumb);

    void setElectros(int money);

    void setColor(string col);

    int getCountry();

    int getNumOfPlayers();

    int getNumberOfElectros();

    string getColor();

    void displayMessage();

private:
    int country;
    int numOfPlayers;
    string nameOfCompany;
    int electros;
    string color;

};



#endif /* GamePlay_h */
