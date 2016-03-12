//
//  Resources.h
//  Power Grid
//
//  Created by Athena on 2016-02-21.
//  Copyright © 2016 Athena. All rights reserved.
//

#ifndef Resources_h
#define Resources_h

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Resources class definition
// Resources.h

class Resources {

public:
    Resources();
    Resources(string resColor);
    ~Resources();  // Destructor

    // GETTTERS
    string getResColor();

    // SETTERS
    void setResColor(string resColor);

    void displayMessage();

protected:
    string resColor;
};

#endif /* Resources_h */
