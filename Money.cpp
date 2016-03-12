
//  Money.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-18.
//  Copyright © 2016 Athena. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include<string>
#include "Money.h"

using namespace std;

// default constructor
Money::Money()
{
	setMoney(50);
}

// constructor
Money::Money(int money)
{
	setMoney(money);
}
Money::~Money()  //Destructor
{

}

 // Getters
 int Money::getMoney()
 {
	 return elektros;
 }

    // Setters
 void Money::setMoney(int money)
 {
	 elektros = money;
 }


 void Money::displayMessage()
 {
	 cout << "The amount of elektros is $" << getMoney() << endl;
 }

