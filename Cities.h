/*
 * Cities.h
 *
 *  Created on: Mar 4, 2016
 *      Author: ALAIN2
 */

#ifndef INDIVIDUALPART2_CITIES_H_
#define INDIVIDUALPART2_CITIES_H_
#include<string>
#include<vector>

using namespace std;

//cities class with method data types declarations
class Cities{
private:
	int numberCities;
	string cityName, cityConnected;
	string cityList;
	string playZones;
	int cityPrice, connectCost;



public:
	Cities(){};
	~Cities();
	void setNumberCities(int city);
	void setNumberCities();
	int getNumberCities();

	void setBuyCities();

	void setCitiesName(string cityName);
	string getCitiesName();

	void setConnectionCost(int cost);
	int getConnectionCost(int cost);
	void setConnectedTo(string city);
	string getConnectedTo();

	void setCitiesList(string cityNames);
	string getCitiesList();

	void setZones(string zone);
	string getZones();

	int stepOneCityPrice();
	int steptwoCityPrice();
	int stepthreeCityPrice();
};

#endif /* INDIVIDUALPART2_CITIES_H_ */
