#pragma once
#include "ItemToPurchase.h"
#include <vector>
class ShoppingCart {
public:
	ShoppingCart(string shopperName = "none", string shoppingDate = "January 1, 2016");
	string GetCustomer();
	void SetCustomer(string shopperName);
	string GetDate();
	void SetDate(string dateToSet); 
	void AddItem(ItemToPurchase newItem);
	void RemoveItem(string removeItem);
	void UpdateQuantity(string theItemName, int newQuantity); 
	int ShowQuantity();
	double TotalCost();
	void PrintCart(); 
	void PrintDescriptions(); 
	int FindItemIndex(string itemToFind); 
private:
	string customerName;
	string dateOfCart;
	vector<ItemToPurchase> itemsList; 

};