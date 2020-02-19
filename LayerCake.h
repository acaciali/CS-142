#pragma once
#include <iostream>
#include <string>
#include "Cake.h"
using namespace std; 

class LayerCake : public Cake {
public:
	LayerCake();
	LayerCake(int cakeLayers, double cakePrice = 9.00);
	virtual string ToString();
	void SetLayers(int cakeLayers); 
	virtual double DiscountPrice(int totalQuantity);
private:
	int layers;
	double price;
};