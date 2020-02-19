#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(string shopperName, string shoppingDate) {
	customerName = shopperName;
	dateOfCart = shoppingDate;
}
string ShoppingCart::GetCustomer() {
	return customerName;
}
void ShoppingCart::SetCustomer(string shopperName) {
	customerName = shopperName; 
}
string ShoppingCart::GetDate() {
	return dateOfCart; 
}
void ShoppingCart::SetDate(string dateToSet) {
	dateOfCart = dateToSet; 
}
void ShoppingCart::AddItem(ItemToPurchase newItem) {
	string checkItemName = newItem.GetName(); 
	bool itemDNE = true; 
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList.at(i).GetName() == checkItemName) {
			cout << "Item is already in cart. Nothing added." << endl;
			itemDNE = false;
		}
	}
	if (itemDNE) {
		itemsList.push_back(newItem);
	}
}
void ShoppingCart::RemoveItem(string removeItem) {
	int itemIndex = FindItemIndex(removeItem); 
	if (itemIndex == -1) {
		cout << "Item not found in cart. Nothing removed." << endl;
	}
	else {
		itemsList.erase(itemsList.begin() + itemIndex);

	}
}
void ShoppingCart::UpdateQuantity(string theItemName, int newQuantity) {
	int itemIndex = FindItemIndex(theItemName); 
	if (itemIndex == -1) {
		cout << "Item not found in cart. Nothing modified." << endl;
	}
	else {
		itemsList.at(itemIndex).SetQuantity(newQuantity);
	}
}
int ShoppingCart::ShowQuantity() {
	int quantityTotal = 0; 
	int quantityPerItem = 0; 
	for (int i = 0; i < itemsList.size(); i++) {
		quantityPerItem = itemsList.at(i).GetQuantity();
		quantityTotal += quantityPerItem; 
	}
	return quantityTotal; 
}
double ShoppingCart::TotalCost() {
	double costTotal = 0; 
	double costPerItem = 0; 
	for (int i = 0; i < itemsList.size(); i++) {
		costPerItem = itemsList.at(i).GetPrice() * itemsList.at(i).GetQuantity();
		costTotal += costPerItem; 
	}
	return costTotal; 
}
void ShoppingCart::PrintCart() {
	cout << GetCustomer() << "'s Shopping Cart - " << GetDate() << endl;
	if (itemsList.size() == 0) {
		cout << "Shopping cart is empty." << endl;
	}
	else {
		cout << "Number of items: " << ShowQuantity() << endl << endl; 
		for (int i = 0; i < itemsList.size(); i++) {
			cout << fixed << setprecision(2); 
			cout << itemsList.at(i).GetName() << " " << itemsList.at(i).GetQuantity() << " @ $" << itemsList.at(i).GetPrice() << " = $" << itemsList.at(i).GetQuantity() * itemsList.at(i).GetPrice() << endl;
		}
		cout << "Total: $" << TotalCost() << endl; 
	}
}
void ShoppingCart::PrintDescriptions() {
	cout << GetCustomer() << "'s Shopping Cart - " << GetDate() << endl << endl;
	if (itemsList.size() == 0) {
		cout << "Shopping cart is empty." << endl;
	}
	else {
		cout << "Item Descriptions" << endl;

		for (int i = 0; i < itemsList.size(); i++) {
			cout << fixed << setprecision(2); 
			cout << itemsList.at(i).GetName() << ": " << itemsList.at(i).GetDescription() << endl;
		}
	}
}
int ShoppingCart::FindItemIndex(string itemToFind) {
	int itemIndex = -1;
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList.at(i).GetName() == itemToFind) {
			itemIndex = i; 
		}
	}

	return itemIndex; 
}