/*
 * PlayerOrder.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: ALAIN2
 */
#include<stdlib.h>
#include"PlayerOrder.h"

using namespace std;

PlayerOrder::PlayerOrder(){};

PlayerOrder::~PlayerOrder(){};

void PlayerOrder::setPlayerOrder(int order){
	playersOrder = order;

}

void PlayerOrder::setPlayerOrder(){
	playerOrder = 0;
}

int PlayerOrder::getPlayerOrder(){
		return playersOrder;

}



