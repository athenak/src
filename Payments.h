/*
 * Payments.h
 *
 *  Created on: Mar 4, 2016
 *      Author: ALAIN2
 */

#ifndef INDIVIDUALPART2_PAYMENTS_H_
#define INDIVIDUALPART2_PAYMENTS_H_

class Payments{
private:
	int totalPayments;
public:
	Payments();
	~Payments();

	void setTotalPayments(int cities);
	void setTotalPayments();
	int getTotalPayments();
};



#endif /* INDIVIDUALPART2_PAYMENTS_H_ */
