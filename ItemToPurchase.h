#pragma once
class ItemToPurchase {
public:
	ItemToPurchase(string productName = "none", string productDescription = "none", double productPrice = 0.0, int productQuantity = 0); 
	string GetName();
	string GetDescription();
	double GetPrice();
	int GetQuantity();


	void SetName(string productName);
	void SetDescription(string productDescription);
	void SetPrice(double productPrice);
	void SetQuantity(int productQuantity);

	void PrintProductPrice(ItemToPurchase currentProduct);
	void PrintProductDescription(ItemToPurchase currentProduct);

private:
	string itemName;
	string itemDescription;
	double itemPrice;
	int itemQuantity;
};
