/********************************************************************************
**Program: ex12_1.cpp
**Author: Holly Harmon
**Description: For exercise 12 question 1. This program contains a class for an
inventory of a consignment/antique shop. The class creates objects that are items
in the shops inventory. The member values for each item are name, age, color, 
the asking price, and the price paid for the item. The details are input to 
constructors that create the item/object.
**Input: The user enters the values in a constructor and the values are
assigned based on what is entered in the call. The user must enter at least
a "name" and "asking price" for an item to be created.
**Output: Uses a member function of the class to print out the name, age, color,
asking price, and purchase price of an item in inventory.
********************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class InventoryItem //inventory list
{
public:
	//The following constructors create item objects with the input arguments
	//set to the appropriate member values.
	InventoryItem(string nameValue, double askValue, int ageVal, string colorValue,
		double paidValue);
	InventoryItem(string nameValue, double askValue, string colorValue, 
		double paidValue);
	InventoryItem(string nameValue, double askValue, int ageVal, double paidValue);
	InventoryItem(string nameValue, double askValue, int ageVal, string colorValue);
	InventoryItem(string nameValue, double askValue, int ageVal);
	InventoryItem(string nameValue, double askValue, string colorValue);
	InventoryItem(string nameValue, double askValue, double paidValue);
	InventoryItem(string nameValue, double askValue);
	InventoryItem( );

	//get functions for the member values
	int getAge( );
	double getAsk( );
	double getPaid( );
	string getColor( );
	string getName( );
	//Out puts the item information
	void itemOutput( );

private:
	string name;
	int age; //in # of years
	string color; 
	double askPrice;
	double paidPrice;

};

int main( )
{
	InventoryItem childToy1("Toy Race Car", 5.99);
	InventoryItem table1("Dining Table", 1100.00, 76, "Mahogany", 850.00);
	InventoryItem childToy2("Porcelain Doll", 40.00, 60);

	childToy1.itemOutput( );
	table1.itemOutput( );
	childToy2.itemOutput( );

	return 0;
}

//The following contructors assign values to the member functions. If no vlaue 
//is input by the user: age = 0, color = "unknown", and price paid = 0.00.
InventoryItem::InventoryItem(string nameValue, double askValue, int ageVal, 
	string colorValue, double paidValue)
{
	name = nameValue;
	askPrice = askValue;
	age = ageVal;
	color = colorValue;
	paidPrice = paidValue;
}

InventoryItem::InventoryItem(string nameValue, double askValue, string colorValue, 
	double paidValue)
{
	name = nameValue;
	askPrice = askValue;
	age = 0;
	color = colorValue;
	paidPrice = paidValue;
}

InventoryItem::InventoryItem(string nameValue, double askValue, int ageVal, 
	double paidValue)
								: name(nameValue), askPrice(askValue), age(ageVal), 
								paidPrice(paidValue)
{
	color = "unknown";
}

InventoryItem::InventoryItem(string nameValue, double askValue, int ageVal, string colorValue)
								: name(nameValue), askPrice(askValue), age(ageVal), color(colorValue)
{
	paidPrice = 0.00;
}

InventoryItem::InventoryItem(string nameValue, double askValue, int ageVal)
								: name(nameValue), askPrice(askValue), age(ageVal)
{
	color = "unknown";
	paidPrice = 0.00;
}

InventoryItem::InventoryItem(string nameValue, double askValue, string colorValue)
								: name(nameValue), askPrice(askValue), color(colorValue)
{
	age = 0;
	paidPrice = 0.00;
}

InventoryItem::InventoryItem(string nameValue, double askValue, double paidValue)
								: name(nameValue), askPrice(askValue), paidPrice(paidValue)
{
	color = "unknown";
	age = 0;
}

InventoryItem::InventoryItem(string nameValue, double askValue)
								: name(nameValue), askPrice(askValue)
{
	age = 0;
	color = "unknown";
	paidPrice = 0.00;
}

InventoryItem::InventoryItem( )
{
	cout << "This item needs at least a name and price to be entered.\n";
}

string InventoryItem::getName( )
{
	return name;
}

int InventoryItem::getAge( )
{
	return age;
}

string InventoryItem::getColor( )
{
	return color;
}

double InventoryItem::getAsk( )
{
	return askPrice;
}

double InventoryItem::getPaid( )
{
	return paidPrice;
}

void InventoryItem::itemOutput( )
{
	cout << "Item Name: " << name << endl;
	cout << "Item Asking Price: $" << askPrice << endl;
	cout << "Item Age: " << age << endl;
	cout << "Item Color: " << color << endl;
	cout << "Item Price Paid: $" << paidPrice << endl << endl;
}