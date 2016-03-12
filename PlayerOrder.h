/*
 * PlayerOrder.h
 *
 *  Created on: Mar 5, 2016
 *      Author: ALAIN2
 */

#ifndef INDIVIDUALPART2_PLAYERORDER_H_
#define INDIVIDUALPART2_PLAYERORDER_H_


class PlayerOrder{
private:
	int playerOrder = 0;
	int playerNumber = 0;
	int playersOrder = 0;

public:

	PlayerOrder();
	~PlayerOrder();
	void setPlayerOrder(int numberPlayers);
	void setPlayerOrder();
	int getPlayerOrder();

};


#endif /* INDIVIDUALPART2_PLAYERORDER_H_ */
