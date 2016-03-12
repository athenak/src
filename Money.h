//
//  Money.h
//  Power Grid
//
//  Created by Athena on 2016-02-18.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Money_h
#define Money_h

#include <stdio.h>
#include <iostream>
#include<string>

using namespace std;

// Money class definition
// Money.h

class Money
{
public:
	Money();
	Money(int money);
    ~Money();  //Destructor

    // Getters
    int getMoney();

    // Setters
    void setMoney(int money);

    void displayMessage();

private:
    int elektros;
};

#endif /* Money_h */
