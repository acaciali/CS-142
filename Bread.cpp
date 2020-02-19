#include "BakedGood.h"
#include "Bread.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std; 

Bread::Bread() {
	variety = ""; 
	price = 4.50;
}

Bread::Bread(string breadVariety, double breadPrice) : BakedGood() {
	variety = breadVariety;
	this->SetPrice(breadPrice); 
}

string Bread::ToString() {
	ostringstream breadInfo;
	breadInfo << variety << " bread ($" << fixed << setprecision(2) << GetPrice() << ")"; 
	return breadInfo.str();
}

void Bread::SetVariety(string breadVariety) {
	variety = breadVariety;
}

double Bread::DiscountPrice(int totalQuantity) {
	int numThrees = totalQuantity / 3; 
	return (this->GetPrice() * totalQuantity) - (this->GetPrice() * numThrees);
}

