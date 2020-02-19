#pragma once
#include <string>
#include "Cake.h"
using namespace std; 

class Cupcake : public Cake {
public:
	Cupcake(); 
	Cupcake(string cupcakeSprinklesColor, double cupcakePrice = 1.95);
	virtual string ToString();
	void SetSprinkesColor(string cupcakeSprinklesColor); 
	string GetSprinklesColor(); 
	virtual double DiscountPrice(int totalQuantity); 
private:
	string sprinklesColor; 
	double price; 
};