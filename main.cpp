//
//  main.cpp
//  Power Grid
//
//  Created by Athena on 2016-02-07.
//  Copyright © 2016 Athena. All rights reserved.
//	Student ID: 22403641

#include <iostream>
#include <vector>
#include<string>
#include "GamePlay.h"
#include <fstream>
#include<limits>
#include "Player.h"
#include "PowerPlant.h"
#include "Houses.h"
#include "Coal.h"
#include "Resources.h"
#include "Country.h"
#include "Garbage.h"
#include "Oil.h"
#include "Uranium.h"
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "Money.h"
#include"Cities.h"
#include"Payments.h"
#include"PlayerOrder.h"

using namespace std;

int phase = 1;

enum GameStates { MAIN_MENU, EXIT, PLAYING, OPTIONS, RANDOM_NUMBER };
//enum HomeColors { RED, GREEN, BLACK, YELLOW, BLUE, BROWN };
bool homColorsTaken[6];  // array to hold HomeColors if taken

void DisplayGamePlayMenu(){
    	cout<<"1: Determine payments.\n2: Playing strategy.\n3: Bid on power plants\n4: Buy resources\n5: Activate power plant\n6: Buy city\n9: Next player's turn."<<endl;
    }

void displayPowerPlant(PowerPlant& powerplantNew)
{
		cout << "The minimum bid for this Power Plant is " << powerplantNew.getMinBid() << endl;
	    cout << "The minimum number of resources needed to produce power for this Power Plant is " << powerplantNew.getMinResToProdPow() << endl;
	    cout << "The maximum amount of resources that can be stored in this plant is " << powerplantNew.getStoreAmountRes() << ". " << endl << "This power plant uses " <<  powerplantNew.getResType() << " to run. " << endl;
	    cout << "It can power " << powerplantNew.getHowManyCitiesCanPower() << " number of cities." << endl;
}

const string Germany;
const string USA;
int country;

// number of players, chosen by the user (input)
int playerNum;

// playerID
int playID = 0;

// player Name
string playerName;

// company name of the player
string playerCompanyName;

// currency
int playerElectros = 0;

// declare constant variables for total amount of wooden houses in the game
const int  WOODENHOUSES = 132;

// declare const number of houses per player of the color chosen
const int HOUSESPERPLAYER = 22;

// declare const number of elektros per player of the color chosen
const int ELEKTROSPERPLAYER = 50;

// color of house that each player chooses, to be used in a switch statement
int colHouse;

string colorHouse;
int choice;
  bool goodChoice = true;
	int numberCities = 0;
	int numberOfCities = 0;
	int totalPayments = 0;
	int numberPowerPlants = 0;
	int roundNumber = 1;
	int colorChoice = 0;
	string playerColor = "";
	string colors[]={"Red", "Green", "Black", "Yellow", "Blue", "Brown"};
	bool goodColor = true;
	int firstPlayer = 0;
	bool bid;

// initial placement of house of each player on 0 area in skyline icons on board (scoring track)
int placementSpaceInCities = 0;

// RESOURCES --> FUEL CONSTANT TOTAL NUMBERS
const int COALTOTALRESOURCES = 24;
const int OILTOTALRESOURCES = 24;
const int GARBAGETOTALRESOURCES = 24;
const int URANIUMTOTALRESOURCES = 12;

// SET UP THE FUEL SUPPLY

// 3 Coal Objects
Coal coalSupply1(1, 1, 1);
Coal coalSupply2(1, 3, 3);
Coal coalSupply3(1, 7, 7);

// 3 Oil Objects
Oil oilSupply1(1, 3, 3);
Oil oilSupply2(1, 5, 5);
Oil oilSupply3(1, 6, 6);

// 3 Garbage Objects
Garbage garbageSupply1(1, 7, 7);
Garbage garbageSupply2(1, 8, 8);
Garbage garbageSupply3(2, 8, 8);

// BUREAUCRACY - PHASE 5 - setup for next iteration (payment to each player for # of cities supplying power)
// An array of the number of Electros earned for powering a number of cities (i.e. A player that does not supply any city gets 10 Elec tro)
int electrosPerNumCitiesSupplied [21] = { 10, 22, 33, 44, 54, 64, 73, 82, 90, 98, 105, 112, 118, 124, 129, 134, 138, 142, 145, 148, 150 };

int gameStartChoice;
GameStates gameState;

// define gameStartChoice function, a menu that prompts the user if they want to play or exit,etc

int gameChoice()
{
    cout<< "Please select:" << endl;
    cout<< "           1. To play Power Grid" << endl;
    cout<< "           2. To Exit" << endl;
    int gameStartChoice;
    cin >> gameStartChoice;
    while (cin.fail())
    {
    	cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(),'\n');
    	cout<<"Enter a valid number! "<<endl;
    	cout<< "           1. To play Power Grid" << endl;
        cout<< "           2. To Exit" << endl;
    	cin>>gameStartChoice;
    }
    while (gameStartChoice < 1 || gameStartChoice > 2)
        {
        	cout<<"Enter a valid number! "<<endl;
        	cout<< "           1. To play Power Grid" << endl;
          cout<< "           2. To Exit" << endl;
        	cin>>gameStartChoice;
        }
    return gameStartChoice;
}

void DisplayColorChoiceMenu(){
	cout << "Enter 1 for RED" << endl;
	cout << "Enter 2 for GREEN" << endl;
	cout << "Enter 3 for BLACK" << endl;
	cout << "Enter 4 for YELLOW" << endl;
	cout << "Enter 5 for BLUE" << endl;
	cout << "Enter 6 for BROWN" << endl<< endl;
}
// variable to end game with a pause
int endGame;



int main()
{
	// GameStates gameState;
    cout<< "Welcome to the Power Grid game!" << endl << endl;

    int gameStartChoice = gameChoice();


    switch (gameStartChoice)
    {

    	case 1:
            cout <<"Let's play Power Grid!" << endl << endl;
            gameState = MAIN_MENU;

            break;
        case 2:
            cout << endl << "Exiting game." << endl << "Good bye!" << endl;
            return 0;
            break;
        default:
            break;
    }

   // GameStates gameState = MAIN_MENU;
    if (gameState == RANDOM_NUMBER)
    {
    	srand(time(0));
    	cout << rand() << endl;
    }
    if (gameState == MAIN_MENU)
    {



        //Start Playing Game!!

        cout << "Please select a country (Germany or USA)" << endl;
        cout << "Please select 1 for Germany or 2 for USA: ";
        cin >> country;

        if(country == 1){
        	cout<<"The Germany map will be available in the future.\nThe game will be set up with the USA map.\n"<<endl;
            country = 2;
        }

        while (cin.fail())
        {
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(),'\n');
        	cout<<"Enter a valid number! "<<endl;
            cout << "Please select 1 for Germany or 2 for USA: ";
        	cin>>country;
        }

        while (country  < 1 || country > 2)
        {
            cout << "You entered an incorrect choice! Please try again." << endl<< endl;
            cout << "Please select a country (Germany or USA)" << endl;
            cout << "Please select 1 for Germany or 2 for USA: ";
            cin >> country;
            while (cin.fail())
            {
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(),'\n');
            	cout<<"Enter a valid number! "<<endl;
                cout << "Please select 1 for Germany or 2 for USA: ";
            	cin>>country;
            }

        }  //  end of country selection (Germany or USA)

        // load power plant cards to file
        fstream binaryio;  // create stream object
        binaryio.open("powerPlant.dat", ios::out | ios::binary);

        //load the powerPlant cards into the file

        // PowerPlant Card Constructors for all cards
        PowerPlant powerPlant03(3, 2, 4,"Oil", 1, false, false);
        PowerPlant powerPlant04(4, 2, 4,"Coal", 1, false, false);
        PowerPlant powerPlant05(5, 2, 4,"Oil or Coal", 1, true, false);
        PowerPlant powerPlant06(6, 1, 2,"Garbage", 1, false, false);
        PowerPlant powerPlant07(7, 3, 6,"Oil", 2, false, false);
        PowerPlant powerPlant08(8, 3, 6,"Coal", 2, false, false);
        PowerPlant powerPlant09(9, 1, 2,"Oil", 1, false, false);
        PowerPlant powerPlant10(10, 2, 4,"Coal", 2, false, false);
        PowerPlant powerPlant11(11, 1, 2,"Uranium", 2, false, false);
        PowerPlant powerPlant12(12, 2, 4,"Oil or Coal", 2, true, false);
        PowerPlant powerPlant13(13, 0, 0,"Ecological", 1, false, true);
        PowerPlant powerPlant14(14, 2, 4,"Garbage", 2, false, false);
        PowerPlant powerPlant15(15, 2, 4,"Coal", 3, false, false);
        PowerPlant powerPlant16(16, 2, 4,"Oil", 3, false, false);
        PowerPlant powerPlant17(17, 1, 2,"Uranium", 2, false, false);
        PowerPlant powerPlant18(18, 0, 0,"Ecological", 2, false, true);
        PowerPlant powerPlant19(19, 2, 4,"Garbage", 3, false, false);
        PowerPlant powerPlant20(20, 3, 6,"Coal", 5, false, false);
        PowerPlant powerPlant21(21, 2, 4,"Oil or Coal", 4, true, false);
        PowerPlant powerPlant22(22, 0, 0,"Ecological", 2, false, true);
        PowerPlant powerPlant23(23, 3, 6,"Uranium", 3, false, false);
        PowerPlant powerPlant24(24, 2, 4,"Garbage", 4, false, false);
        PowerPlant powerPlant25(25, 2, 4,"Coal", 5, false, false);
        PowerPlant powerPlant26(26, 2, 4,"Oil", 5, false, false);
        PowerPlant powerPlant27(27, 0, 0,"Ecological", 3, false, true);
        PowerPlant powerPlant28(28, 1, 2,"Uranium", 4, false, false);
        PowerPlant powerPlant29(29, 1, 2,"Oil or Coal", 4, true, false);
        PowerPlant powerPlant30(30, 3, 6,"Garbage", 6, false, false);
        PowerPlant powerPlant31(31, 3, 6,"Coal", 6, false, false);
        PowerPlant powerPlant32(32, 3, 6,"Oil", 6, false, false);
        PowerPlant powerPlant33(33, 0, 0,"Ecological", 4, false, true);
        PowerPlant powerPlant34(34, 1, 2,"Uranium", 5, false, false);
        PowerPlant powerPlant35(35, 1, 2,"Oil", 5, false, false);
        PowerPlant powerPlant36(36, 3, 6,"Coal", 7, false, false);
        PowerPlant powerPlant37(37, 0, 0,"Ecological", 4, false, true);
        PowerPlant powerPlant38(38, 3, 6,"Garbage", 7, false, false);
        PowerPlant powerPlant39(39, 1, 2,"Uranium", 6, false, false);
        PowerPlant powerPlant40(40, 2, 4,"Oil", 6, false, false);
        PowerPlant powerPlant42(42, 2, 4,"Coal", 6, false, false);
        PowerPlant powerPlant44(44, 0, 0,"Ecological", 5, false, true);
        PowerPlant powerPlant46(46, 3, 6,"Oil or Coal", 7, true, false);
        PowerPlant powerPlant50(50, 0, 0,"Ecological", 6, false, true);
        PowerPlant powerPlant0(0, 0, 0,"Step 3", 0, false, false);  // THE "STEP 3" CARD


        // writing the PowerPlant constructors above to a binary file called powerPlant.dat

        binaryio.write(reinterpret_cast<char*>(&powerPlant03), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant04), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant05), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant06), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant07), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant08), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant09), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant10), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant11), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant12), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant13), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant14), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant15), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant16), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant17), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant18), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant19), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant20), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant21), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant22), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant23), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant24), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant25), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant26), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant27), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant28), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant29), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant30), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant31), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant32), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant33), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant34), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant35), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant36), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant37), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant38), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant39), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant40), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant42), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant44), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant46), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant50), sizeof(PowerPlant));
        binaryio.write(reinterpret_cast<char*>(&powerPlant0), sizeof(PowerPlant));


        // close the powerPlant.dat file
        binaryio.close();


        vector<PowerPlant> myPowerPlant;  //myPowerPlant vector is empty

        cout << "Please select how many players will be playing today (2 to 6) : ";
        cin >> playerNum;
        while (cin.fail())
        {
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(),'\n');
        	cout<<"Enter a valid number? "<<endl;
        	cout << "Please select how many players will be playing today (2 to 6) : ";
        	cin>>playerNum;
        }

        // making sure that players are between 2 and 6
        while (playerNum < 2 || playerNum > 6)
        {
            cout << endl << "Please select how many players will be playing today (2 to 6) : ";
            cin >> playerNum;
            while (cin.fail())
            {
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(),'\n');
            	cout<<"Enter a valid number? "<<endl;
            	cout << "Please select how many players will be playing today (2 to 6) : ";
            	cin>>playerNum;
            }
        }  // end of player number selection 2 to 6

        // Player vector
        vector<Player> players(playerNum);

        vector<unsigned int>playersOrders(playerNum+1);
        for(int i = 0; i < playerNum; i++){
        	int *Order = new int();
        	playersOrders[i] = *Order;
        }

        GamePlay newGame(country, playerNum);
        newGame.displayMessage();

        // Set up each PLAYER:
        //instantiate player object with initial values
        	for(int i = 0; i < playerNum; i++){
        		Player *player = new Player();
        		players[i] = *player;
        	}



        // playID = 1 now
        playID++;

        // while less than or equal to total players (between 2 and 6)
        // setup each Player
        for(int j = 0; j < playerNum; j++){

					cout << "\n\nSetting up Player Number: " << playID << endl << endl;

					// get player Name from the user (player)
					cout << "Please enter your name: " << endl;
					cin >> playerName;

					// making sure a player name is entered
					while(playerName == "")
					{
						cout << endl << "Please enter your name: " << endl;
						cin >> playerName;
					}

					// enter Company name associated with the user (player)
					cout << "Please enter your Company name: " << endl;
					cin >> playerCompanyName;

					// making sure a Company name is entered
					while(playerCompanyName == "")
					{
						cout << endl << "Please enter your Company name: " << endl;
						cin >> playerCompanyName;
					  }

				cout << "Please enter the color of your houses from the following choices: " << endl << endl;
				DisplayColorChoiceMenu();
				cin >> colHouse;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<"Enter a valid number! "<<endl;
					DisplayColorChoiceMenu();
					cin>>colHouse;
				}

				while (colHouse < 1 || colHouse > 6)
				{
					cout << "Please select a valid choice: "  << endl;
					DisplayColorChoiceMenu();
					cin >> colHouse;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<<"Enter a valid number! "<<endl;
						DisplayColorChoiceMenu();
						cin>>colHouse;
					}
				}

				colorHouse = colors[colHouse-1];

			   do{
			   			for(int i = 0; i < 6; i++){
			   				if(j > 0){
			   					if(colorHouse == players[j-1].getPlayerColor()){
			   						goodColor = false;
			   						}else{
			   						   goodColor = true;
			   						   players[j] = Player(playID, playerName,colorHouse,HOUSESPERPLAYER,ELEKTROSPERPLAYER,playerCompanyName);
									   players[j].displayMessage();
									   break;
			   						}
			   				}else{
									goodColor = true;
									players[j] = Player(playID, playerName,colorHouse,HOUSESPERPLAYER,ELEKTROSPERPLAYER,playerCompanyName);
									players[j].displayMessage();
									break;
			   					}

			   			}

			   			if(!goodColor){
			   				cout << "Please select a valid choice: "  << endl;
			   				DisplayColorChoiceMenu();
			   				cin >> colHouse;
							while (cin.fail())
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(),'\n');
								cout<<"Enter a valid number! "<<endl;
								DisplayColorChoiceMenu();
								cin>>colHouse;
							}
			   				colorHouse = colors[colHouse-1];
			   			}
			   		}while(!goodColor);
				// ENDS HOUSE COLOR SELECTION

					   // increment playID++;
					   playID++;



			  // end of gameState = MAIN_MENU


        }
 //////////////////////////////////////////////////////////////////////////////////////////
 //////////////////player order selection/////////////////////////////////////////////////
		if(roundNumber == 1){
			cout<<"\n\nRound number: "<<roundNumber<<endl;
//			unsigned int playerNumber = players.size();

			unsigned int temp = 0;
			srand(time(NULL));
			for(unsigned int k =0; k < players.size(); k++){
				playersOrders[k] = rand() % 1000;
				players[k].setPlayerTurn(playersOrders[k]);
				if(playersOrders[k] > temp){
					temp = playersOrders[k];
					firstPlayer=k;
				}
			}

			cout<<"The first player is "<<players[firstPlayer].getPlayerName()<<"\nYou will start round: "<<roundNumber<<" and be the first player to buy power plants and to go through the Bureaucracy phase."<<endl;
			players[firstPlayer].setPlayerTurn(0);
			playersOrders[0] =	firstPlayer;
			int counter =1;
			for(int k =0; k < signed(players.size()); k++){

				if(k!= firstPlayer){
					cout<<"The next player is "<<players[k].getPlayerName()<<"\nYou will be the player to start the Buying Raw Materials phase and the Building phase\n"<<endl;
					players[k].setPlayerTurn(1);
					playersOrders[counter] =	k;
					counter++;
				}
			}
			roundNumber++;

		}else{
			cout<<"\n\nRound number: "<<roundNumber<<endl;
			unsigned int temp[players.size()];
					for(unsigned int k = 0;k < players.size()-1; k++ ){
						if(players[k].getNumberCities() != players[k+1].getNumberCities()){
							if(players[k].getNumberCities() < players[k+1].getNumberCities()){
								temp[k] = {k+1};
								firstPlayer=temp[k];
								playersOrders[0] =	firstPlayer;
								int counter =1;

								cout<<"The first player is "<<players[firstPlayer].getPlayerName()<<"\nYou will start round: "<<roundNumber<<" and be the first player to buy power plants and to go through the Bureaucracy phase."<<endl;
								for(unsigned int k =0; k < players.size(); k++){

									if(signed(k) != signed(firstPlayer)){
										cout<<"The next player is "<<players[k].getPlayerName()<<"\nYou will be the player to start the Buying Raw Materials phase and the Building phase\n"<<endl;
										players[k].setPlayerTurn(1);
										playersOrders[counter] =	k;
										counter++;
									}
								}
							}else{
								firstPlayer=k;
								playersOrders[0] =	firstPlayer;
								int counter =1;

								cout<<"The first player is "<<players[firstPlayer].getPlayerName()<<"\nYou will start round: "<<roundNumber<<" and be the first player to buy power plants and to go through the Bureaucracy phase."<<endl;
								for(unsigned int k =0; k < players.size(); k++){

									if(signed(k) != signed(firstPlayer)){
										cout<<"The next player is "<<players[k].getPlayerName()<<"\nYou will be the player to start the Buying Raw Materials phase and the Building phase\n"<<endl;
										players[k].setPlayerTurn(1);
										playersOrders[counter] =	k;
										counter++;
									}
								}
							}

						}else{
							if(players[k].getPlayerNumberOfPowerPlants() < players[k+1].getPlayerNumberOfPowerPlants()){
								temp[k] = {k+1};
								firstPlayer=temp[k];
								playersOrders[0] =	firstPlayer;
								int counter =1;

								cout<<"The first player is "<<players[firstPlayer].getPlayerName()<<"\nYou will start round: "<<roundNumber<<" and be the first player to buy power plants and to go through the Bureaucracy phase."<<endl;
								for(unsigned int k =0; k < players.size(); k++){

									if(signed(k) != signed(firstPlayer)){
										cout<<"The next player is "<<players[k].getPlayerName()<<"\nYou will be the player to start the Buying Raw Materials phase and the Building phase\n"<<endl;
										players[k].setPlayerTurn(1);
										playersOrders[counter] =	k;
										counter++;
									}
								}
							}else{
								firstPlayer=k;
								playersOrders[0] =	firstPlayer;
								int counter =1;

								cout<<"The first player is "<<players[firstPlayer].getPlayerName()<<"\nYou will start round: "<<roundNumber<<" and be the first player to buy power plants and to go through the Bureaucracy phase."<<endl;
								for(unsigned int k =0; k < players.size(); k++){

									if(signed(k) != signed(firstPlayer)){
										cout<<"The next player is "<<players[k].getPlayerName()<<"\nYou will be the player to start the Buying Raw Materials phase and the Building phase\n"<<endl;
										players[k].setPlayerTurn(1);
										playersOrders[counter] =	k;
										counter++;
									}
								}
							}
						}

					}
					roundNumber++;
		}


    ///////////////////////////////////////////////////////////////////////////////////////////

    //RESOURCES TAKEN CARE OF NOW - PART 2 OF THE GAME BEGINS

    // SHOW RESOURCES;
    cout << "                RESOURCE MARKET\n"  << endl << endl;

    cout << "There are 4 types of Resources to fuel the power plants. They are:"  << endl;
    cout << endl << "      COAL       Total of 24 tokens, the color is BROWN" << endl;
    cout << endl << "      OIL        Total of 24 tokens, the color is BLACK" << endl;
    cout << endl << "      GARBAGE    Total of 24 tokens, the color is YELLOW" << endl;
    cout << endl << "      URANIUM    Total of 12 tokens, the color is RED\n" << endl;

    cout << "\nSetting up 3 COAL Resources to start the game.\n" << endl;
    // 3 Coal resources instantiated above main
    coalSupply1.displayMessage();
    coalSupply2.displayMessage();
    coalSupply3.displayMessage();

    // 3 Oil resources instantiated above main
    cout << "\nSetting up 3 OIL Resources to start the game." << endl;
    oilSupply1.displayMessage();
    oilSupply2.displayMessage();
    oilSupply3.displayMessage();

    // 3 Garbage resources instantiated above main
    cout << "\nSetting up 3 GARBAGE Resources to start the game." << endl;
    garbageSupply1.displayMessage();
    garbageSupply2.displayMessage();
    garbageSupply3.displayMessage();

    // 2 Power Plants cards instantiated above display their features
    cout << "\n\n               POWER PLANTS \n"  << endl;

    cout << endl << endl << "The First PowerPlants up for auction are (Power Plant Card): " << endl << endl;

    // Read powerPlant back from the file
    binaryio.open("powerPlant.dat", ios::in | ios::binary);

    PowerPlant powerplantNew;

    cout << "You can only bid on the following 4 cards to start " << endl << endl;
    cout << "POWER PLANTS UP FOR BID:" << endl << endl;
    cout << "MAKE A BID!!!:" << endl << endl;

        cout << "These are a total of 43 Power Plant Cards in the Game!!!:" << endl << endl;

        // load all the 43 PowerPlant objects into the vector from the binary file generated above

        for(int i = 0; i < 43; i++)
        {
            binaryio.read(reinterpret_cast<char*>(&powerplantNew), sizeof(PowerPlant));
           // powerplantNew.displayMessage();
            myPowerPlant.push_back((
                                    PowerPlant(powerplantNew.getMinBid(), powerplantNew.getMinResToProdPow(), powerplantNew.getStoreAmountRes(), powerplantNew.getResType(), powerplantNew.getHowManyCitiesCanPower(), powerplantNew.getIsHybrid(), powerplantNew.getIsEcolOrFusion())));
        }

        cout << "PHASE 1 of the GAME:   You can only bid on the following 4 cards to start " << endl << endl;

        // display the first 4 cards for bidding to start in PHASE 1 of the GAME
        for(int i = 0; i < 4; i++)
        {
            myPowerPlant[i].displayMessage();
        }

        // display the future market 4 cards of PHASE 1 of the GAME
        cout << "PHASE 1 of the GAME:   These are the  4 Future power plant cards open for bidding" << endl << endl;

        for(int i = 4; i < 8; i++)
        {
            myPowerPlant[i].displayMessage();
        }


    // Close the powerPlant.dat file
    binaryio.close();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////game play/////////////////////////////////////////////////////////////////////////////////////

    for(unsigned int j =0; j < players.size(); j++){
       			do{

       				cout<<"\n\n"<<players[(playersOrders[j])].getPlayerName()<<" choose one of the following"<<endl;
       				DisplayGamePlayMenu();
    				cin>>choice;

    				do{
    					if(choice >1 || (choice <7 && choice <=9)){
    						goodChoice = true;
    						break;
    					}else{
    						goodChoice = false;
    					}

    					if(!goodChoice){
    						cout<<"Please enter a valid choice."<<endl;
    						DisplayGamePlayMenu();
    					   	cin>>choice;
    					   	while (cin.fail())
    					   	{
    					   		cin.clear();
    					   		cin.ignore(numeric_limits<streamsize>::max(),'\n');
    					   		cout<<"Enter a valid number! "<<endl;
    					   		DisplayGamePlayMenu();
    					   		cin>>choice;
    					   	}
    					}
    				}while(!goodChoice || choice!=9);


    				switch(choice){
    					case 1:{
    						cout<<"How many cities do you have:";
    						cin>>numberCities;
    						while (cin.fail())
    						{
    							cin.clear();
    							cin.ignore(numeric_limits<streamsize>::max(),'\n');
    							cout<<"Enter a valid number! "<<endl;
    							cout<<"How many cities do you have:";
    							cin>>numberCities;
    						}
    						players[j].setNumberCities(numberCities);
    						numberOfCities = players[j].getNumberCities();

    						cout<<"How many power plants do you have:";
    						cin>>numberPowerPlants;
    						while (cin.fail())
    						{
    							cin.clear();
    							cin.ignore(numeric_limits<streamsize>::max(),'\n');
    							cout<<"Enter a valid number! "<<endl;
    							cout<<"How many power plants do you have:";
    							cin>>numberPowerPlants;
    						}
    						players[j].setNumberPowerPlants(numberPowerPlants);
    						cout<<"Cities: "<<numberOfCities<<"\tPowerPlants: "<<numberPowerPlants<<endl;
    						players[j].setTotalPayments(numberOfCities);
    						totalPayments = players[j].getTotalPayments();
    						cout<<players[j].getPlayerName()<<", your total payment this turn for "<<numberOfCities<<" cities, is "<<totalPayments<<" Electros."<<endl;
    						break;
    					}
    					case 2:{
    						cout<<"\nSummary of playing phases"<<endl;
    						cout<<"1. Determine Turn Order."<<endl;
    						cout<<"\tPlayer Order is determined by the cities in descending order, then highest number of power plants if players have same number of cities.\n";
    						cout<<"\n2. Buy Power Plant (first player begins)\n3. Buy Raw Materials (last player begins)\n4. Building (last player begins)\n5. Bureaucracy (first player starts)\n"<<endl;
    						break;
    					}
    					case 3:

    					    cout << "Would you like to bid or pass ? (select 1 for bid or 0 for pass)" << endl;

        cin >> bid;
    while (cin.fail())
    {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter a valid number! "<<endl;
    cout << "Would you like to bid or pass ? (select 1 for bid or 0 for pass)" << endl;
    cin>>bid;
    while (cin.fail())
    {
    	cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(),'\n');
    	cout<<"Enter a valid number! "<<endl;
        cout << "Would you like to bid or pass ? (select 1 for bid or 0 for pass)" << endl;
    	cin>>bid;
    }
    }
        if(bid == 0 && phase ==1)
        {
                                cout << "You have to bid in Phase 1. " << endl;
                            }
                            else if(bid == 1 && phase ==1)
                            {
                                    //displayPowerPlant(powerplantNew);
                                    // display the first 4 cards for bidding to start in PHASE 1 of the GAME
                                    for(int i = 0; i < 4; i++)
                                    {
                                        myPowerPlant[i].displayMessage();
                                    }
                                    cout << endl;
                                    cout << "The cheapest PowerPlant for auction is PowerPlant # : " << myPowerPlant[0].getMinBid() << endl;
                                    cout << "The mininum bid is " << myPowerPlant[0].getMinBid() << " Elektros"  << endl;
                                    cout << "How much would you like to bid on the Power Plant up for auction?" << endl;
                                    int paymentPlant;
                                    cin >> paymentPlant;
                                    while (cin.fail())
                                    {
                                    	cin.clear();
                                    	cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    	cout<<"Enter a valid number! "<<endl;
                                        cout << "How much would you like to bid on the Power Plant up for auction?" << endl;
                                    	cin>>paymentPlant;
                                    }
                                    while(paymentPlant < myPowerPlant[0].getMinBid())
                                    {
                                        cout << "Too LOW! Bid Higher!" << endl;
                                        cout << "The mininum bid is " << myPowerPlant[0].getMinBid() << " Elektros"  << endl;
                                        cout << "How much would you like to bid on the Power Plant up for auction?" << endl;
                                        cin >> paymentPlant;
                                        while (cin.fail())
                                        {
                                        	cin.clear();
                                        	cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        	cout<<"Enter a valid number! "<<endl;
                                            cout << "How much would you like to bid on the Power Plant up for auction?" << endl;
                                        	cin>>paymentPlant;
                                        }
                                    }
                                    cout << "Bid ACCEPTED!!" << endl;
                                       }else
        {
        cout << "Next player" << endl;
         

    					    }
    					    break;
    					case 4:

    						break;

    					case 5:

    						break;

    					case 6:




    						break;
    				}

    			}while(choice!=9);
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // ending the game
    cout << "\nThank you for playing Power Grid! Our new iteration is due in a few weeks.\nI hope that you enjoyed it.";
    cout << "\nPlease select 0 to end the Game!" << endl;
    cin >> endGame;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Enter a valid number! "<<endl;
		cout << "\nPlease select 0 to end the Game!" << endl;
		cin>>endGame;
	}
    while(endGame == 0)
    	exit(0);
    }

    return 0;
}  // end of main()
