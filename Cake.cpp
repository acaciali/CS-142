#include "Cake.h"
#include "LayerCake.h"
#include "CupCake.h"
#include <iostream>
#include <string>

Cake::Cake() {
	flavor = "";
	frosting = ""; 
}

Cake::Cake(string cakeFlavor, string cakeFrosting) {
	flavor = cakeFlavor;
	frosting = cakeFrosting; 
}

void Cake::SetFlavor(string cakeFlavor) {
	flavor = cakeFlavor;
}

void Cake::SetFrosting(string cakeFrosting) {
	frosting = cakeFrosting; 
}

string Cake::GetFlavor() {
	return flavor;
}

string Cake::GetFrosting() {
	return frosting;
}

