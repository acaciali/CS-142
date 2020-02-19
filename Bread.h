#pragma once
#include <string>
#include "BakedGood.h"
using namespace std; 

class Bread : public BakedGood {
public:
	Bread(); 
	Bread(string breadVariety, double breadPrice = 4.50);
	virtual string ToString(); 
	void SetVariety(string breadVariety);
	virtual double DiscountPrice(int totalQuantity);
private:
	string variety;
	double price;
};