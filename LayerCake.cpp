#include "LayerCake.h"
#include "Cake.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

LayerCake::LayerCake() {
	layers = 0; 
	price = 9.00;
}

LayerCake::LayerCake(int cakeLayers, double cakePrice) {
	layers = cakeLayers;
	this->SetPrice(cakePrice);
}

string LayerCake::ToString() {
	ostringstream cakeInfo;
	cakeInfo << layers << "-layer " << this->GetFlavor() << " cake with " << this->GetFrosting() << " frosting ($" << fixed << setprecision(2) << GetPrice() << ")";
	return cakeInfo.str();
}

void LayerCake::SetLayers(int cakeLayers) {
	layers = cakeLayers; 
}

double LayerCake::DiscountPrice(int totalQuantity) {
	if (totalQuantity >= 3) {
		return (this->GetPrice() * totalQuantity) - (2 * totalQuantity);
	}
	else {
		return this->GetPrice() * totalQuantity; 
	}
}