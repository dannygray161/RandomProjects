#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

void ReadItemData(ItemToPurchase& item, int itemNumber)
{
    string name;
    int price;
    int quantity;

    cout << "Item " << itemNumber << endl;

    // --- Read Name (using getline for multi-word names) ---
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item.SetName(name);

    // --- Read Price ---
    cout << "Enter the item price:" << endl;
    cin >> price;
    item.SetPrice(price);

    // --- Read Quantity ---
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    item.SetQuantity(quantity);

    cout << endl;
}

int main() {
    // Create the two item objects using the default constructor.
    ItemToPurchase item1;
    ItemToPurchase item2;

    // --- Read Item 1 ---
    ReadItemData(item1, 1);

    // --- Input Buffer Fix ---
    // This is required after reading the quantity (int) for item 1 
    // to clear the leftover newline character before reading the string name for item 2.
    cin.ignore(100, '\n');

    // --- Read Item 2 ---
    ReadItemData(item2, 2);

    // --- Calculation ---
    // Calculate the total cost for each item and the grand total.
    int item1Cost = item1.GetPrice() * item1.GetQuantity();
    int item2Cost = item2.GetPrice() * item2.GetQuantity();
    int totalCost = item1Cost + item2Cost;

    // --- Output ---
    cout << "TOTAL COST" << endl;

    // Output Item 1 details
    cout << item1.GetName() << " " << item1.GetQuantity()
        << " @ $" << item1.GetPrice() << " = $" << item1Cost << endl;

    // Output Item 2 details
    cout << item2.GetName() << " " << item2.GetQuantity()
        << " @ $" << item2.GetPrice() << " = $" << item2Cost << endl;

    cout << endl << "Total: $" << totalCost << endl;

    return 0;
}