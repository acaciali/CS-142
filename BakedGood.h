#pragma once
#include <iostream>
#include <string>
using namespace std; 

class BakedGood {
public:
	BakedGood(); 
	BakedGood(int goodQuantity, double goodPrice);
	double GetPrice();
	void SetPrice(double goodPrice); 
	virtual string ToString() = 0;
	virtual double DiscountPrice(int totalquantity) = 0;
	int GetQuantity();
	void SetQuantity(int goodQuantity); 
	void IncrementQuantity(); 

private:
	int quantity;
	double price;
};