/*
 * Cities.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Alain Fallara
 */

#include"Player.h"

using namespace std;
Cities::~Cities(){
}
//option to add number of cities manually
void Cities::setNumberCities(int city){
	this->numberCities = city;
}

//automatically increases number of cities as they are purchased
void Cities::setBuyCities(){
	numberCities++;
}

//initializes number of cities to start game
void Cities::setNumberCities(){
	numberCities = 0;
}

//returns the number of city the player has
int Cities::getNumberCities(){
	return numberCities;
}

//sets the name of the city
void Cities::setCitiesName(string cityName){
	this->cityName = cityName;
}

//gets the name of the city
string Cities::getCitiesName(){
	return cityName;
}

void Cities::setConnectedTo(string city){
	cityConnected = city;
}
string Cities::getConnectedTo(){
	return cityConnected;
}
void Cities::setConnectionCost(int cost){
	connectCost = cost;
}
int Cities::getConnectionCost(int cost){
	return connectCost;
}
void Cities::setCitiesList(string cityNames){
	cityList = cityNames;
}
string Cities::getCitiesList(){
	return cityList;
}
void Cities::setZones(string zones){
	playZones = zones;
}
string Cities::getZones(){
	return playZones;
}
//sets the price of a city in the first step
int Cities::stepOneCityPrice(){
	return cityPrice = 10;
}

//sets the price of the city in step two
int Cities::steptwoCityPrice(){
	return cityPrice = 15;
}

//sets the price of the city in step three
int Cities::stepthreeCityPrice(){
	return cityPrice = 20;
}


