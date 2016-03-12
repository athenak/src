/*
 * Payments.cpp
 *
 *  Created on: Mar 4, 2016
 *      Author: ALAIN2
 */

#include"Payments.h"

using namespace std;

void Payments::setTotalPayments(){
	totalPayments = 0;
}

Payments::Payments(){};

Payments::~Payments(){};

void Payments::setTotalPayments(int cities){
	int payments[] = {10,22,33,44,54,64,73,82,90,98,105,112,118,124,129,134,138,142,145,148,150};
	totalPayments = payments[cities];
}

int Payments::getTotalPayments(){
	return totalPayments;
}


