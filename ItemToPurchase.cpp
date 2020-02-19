#include <iostream> 
#include <string>
using namespace std;

#include "ItemToPurchase.h"
ItemToPurchase::ItemToPurchase(string productName, string productDescription, double productPrice, int productQuantity) {
	itemName = productName;
	itemDescription = productDescription;
	itemPrice = productPrice;
	itemQuantity = productQuantity; 
}
string ItemToPurchase::GetName() {
	return itemName;
}
string ItemToPurchase::GetDescription() {
	return itemDescription;
}
double ItemToPurchase::GetPrice() {
	return itemPrice;
}
int ItemToPurchase::GetQuantity() {
	return itemQuantity;
}

void ItemToPurchase::SetName(string productName) {
	itemName = productName;
}
void ItemToPurchase::SetDescription(string productDescription) {
	itemDescription = productDescription;
}
void ItemToPurchase::SetPrice(double productPrice) {
	itemPrice = productPrice;
}
void ItemToPurchase::SetQuantity(int productQuantity) {
	itemQuantity = productQuantity;
}
void ItemToPurchase::PrintProductPrice(ItemToPurchase currentProduct) {
	cout << currentProduct.GetName() << " " << currentProduct.GetQuantity() << " @ $" << currentProduct.GetPrice() << " = $" << currentProduct.GetPrice() * currentProduct.GetQuantity() << endl;
}
void ItemToPurchase::PrintProductDescription(ItemToPurchase currentProduct) {
	cout << currentProduct.GetName() << ": " << currentProduct.GetDescription() << endl;
}