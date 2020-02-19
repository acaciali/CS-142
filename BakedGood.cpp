#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include <iostream>
#include <string>
using namespace std; 

BakedGood::BakedGood() {
	quantity = 0; 
	price = 0.0;
}

BakedGood::BakedGood(int goodQuantity, double goodPrice) {
	quantity = goodQuantity;
	price = goodPrice;
}

double BakedGood::GetPrice() {
	return price;
}

void BakedGood::SetPrice(double goodPrice) {
	this->price = goodPrice; 
}


int BakedGood::GetQuantity() {
	return quantity;
}

void BakedGood::SetQuantity(int goodQuantity) {
	quantity = goodQuantity; 
}

void BakedGood::IncrementQuantity() {
	quantity++; 
}
