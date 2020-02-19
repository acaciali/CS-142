/*
Acacia Ricks, Section 4, alricks1922@gmail.com
Main Lab 10 - Bread and Cakes
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string> 
#include <sstream>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "LayerCake.h"
#include "CupCake.h"

using namespace std;
int main() {
	vector<BakedGood*> orderVector; 
	string itemInfo; 
	
	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	do {
		cout << "Sub-order: "; 
		getline(cin, itemInfo);
		cout << endl;
		istringstream inSS(itemInfo); 
		string bakedGoodType; 
		inSS >> bakedGoodType; 
		int bakedGoodQuantity; 

		if (bakedGoodType == "Bread") {
			string breadVariety;
			inSS >> breadVariety; 
			inSS >> bakedGoodQuantity; 
			Bread* newBreadPointer = new Bread(breadVariety);
			newBreadPointer->SetQuantity(bakedGoodQuantity);
			for (int i = 0; i < bakedGoodQuantity; i++) {
				orderVector.push_back(newBreadPointer);
			}
		}

		else if (bakedGoodType == "Layer-cake") {
			string cakeFlavor; 
			string frostingFlavor;
			int cakeLayers;
			inSS >> cakeFlavor;
			inSS >> frostingFlavor; 
			inSS >> cakeLayers;
			inSS >> bakedGoodQuantity; 
			LayerCake* newLayerCakePointer = new LayerCake(cakeLayers);
			newLayerCakePointer->SetFlavor(cakeFlavor);
			newLayerCakePointer->SetFrosting(frostingFlavor);
			newLayerCakePointer->SetQuantity(bakedGoodQuantity); 
			double addedPrice = 0; 
			if (cakeLayers > 1) {
				for (int i = 1; i < cakeLayers; i++) {
					addedPrice += 3; 
				}
			}
			newLayerCakePointer->SetPrice(newLayerCakePointer->GetPrice() + addedPrice);
			if (frostingFlavor == "cream-cheese") {
				double newPrice = newLayerCakePointer->GetPrice() + cakeLayers;
				newLayerCakePointer->SetPrice(newPrice); 
			}
			for (int i = 0; i < bakedGoodQuantity; i++) {
				orderVector.push_back(newLayerCakePointer);
			}
		}

		else if (bakedGoodType == "Cupcake") {
			string cakeFlavor;
			string frostingFlavor;
			string sprinklesColor; 
			inSS >> cakeFlavor;
			inSS >> frostingFlavor;
			inSS >> sprinklesColor;
			inSS >> bakedGoodQuantity; 
			Cupcake* newCupcakePointer = new Cupcake(sprinklesColor);
			newCupcakePointer->SetFlavor(cakeFlavor);
			newCupcakePointer->SetFrosting(frostingFlavor);
			newCupcakePointer->SetQuantity(bakedGoodQuantity);
			if (frostingFlavor == "cream-cheese") {
				double newPrice = newCupcakePointer->GetPrice() + 0.20;
				newCupcakePointer->SetPrice(newPrice); 
			}
			for (int i = 0; i < bakedGoodQuantity; i++) {
				orderVector.push_back(newCupcakePointer);
			}
		}
		
	} while (itemInfo != "done"); 

	cout << "Order confirmations: " << endl;
	for (int i = 0; i < orderVector.size(); i++) {
		cout << orderVector.at(i)->ToString() << endl;
	}

	cout << "Invoice:" << endl;
	cout << setw(75) << left << "Baked Good";
	cout << setw(9) << right << "Quantity";
	cout << setw(9) << right << "Total" << endl;
	vector<BakedGood*> invoiceVector; 
	int goodQuantity = 0; 
	int orderQuantity = 0; 
	double orderCharge = 0.00;

	cout << fixed << setprecision(2); 
	for (int i = 0; i < orderVector.size(); i++) {
		bool duplicateOrder = false;
		for (int j = 0; j < invoiceVector.size(); j++) {
			if (invoiceVector.at(j)->ToString() == orderVector.at(i)->ToString()) {
				invoiceVector.at(j)->IncrementQuantity();
				duplicateOrder = true;
			}
		}
		if (!duplicateOrder) {
			orderVector.at(i)->SetQuantity(1); 
			invoiceVector.push_back(orderVector.at(i));
		}
	}

	for (int i = 0; i < invoiceVector.size(); i++) {
		goodQuantity = invoiceVector.at(i)->GetQuantity();
		orderQuantity += goodQuantity; 
		orderCharge += invoiceVector.at(i)->DiscountPrice(goodQuantity); 
		cout << setw(75) << left << invoiceVector.at(i)->ToString();
		cout << setw(9) << right << goodQuantity;
		cout << setw(9) << right << invoiceVector.at(i)->DiscountPrice(goodQuantity) << endl;
	}
		
	cout << setw(75) << left << "Totals";
	cout << setw(9) << right << orderQuantity;
	cout << setw(9) << right << orderCharge << endl;
	cout << "Goodbye"; 

	//system("pause");
	return 0;
}