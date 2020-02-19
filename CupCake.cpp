#include "CupCake.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std; 

Cupcake::Cupcake() {
	sprinklesColor = ""; 
	price = 1.95;
}

Cupcake::Cupcake(string cupcakeSprinklesColor, double cupcakePrice) {
	sprinklesColor = cupcakeSprinklesColor;
	this->SetPrice(cupcakePrice);
}

string Cupcake::ToString() {
	ostringstream cakeInfo;
	cakeInfo << this->GetFlavor() << " cupcake with " << this->GetFrosting() << " frosting and " << this->GetSprinklesColor() << " sprinkles ($" << fixed << setprecision(2) << GetPrice() << ")";
	return cakeInfo.str();
}

void Cupcake::SetSprinkesColor(string cupcakeSprinklesColor) {
	sprinklesColor = cupcakeSprinklesColor; 
}

string Cupcake::GetSprinklesColor() {
	return sprinklesColor;
}

double Cupcake::DiscountPrice(int totalQuantity) {
	if (totalQuantity >= 2 && totalQuantity < 4) {
		return (this->GetPrice() * totalQuantity) - (0.3 * totalQuantity);
	}
	else if (totalQuantity >= 4) {
		return (this->GetPrice() * totalQuantity) - (0.4 * totalQuantity);
	}
	else {
		return this->GetPrice() * totalQuantity; 
	}
}