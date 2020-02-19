#pragma once
#include <iostream>
#include <string>
#include "BakedGood.h"
using namespace std; 
class Cake : public BakedGood {
public:
	Cake();
	Cake(string cakeFlavor, string cakeFrosting);
	virtual string ToString() = 0; 
	void SetFlavor(string cakeFlavor);
	void SetFrosting(string cakeFrosting); 
	string GetFlavor();
	string GetFrosting();
private:
	string flavor;
	string frosting; 
};