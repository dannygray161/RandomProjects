#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

// Parameterized constructor
ItemToPurchase::ItemToPurchase(string name, int price, int quantity) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
}

// Setter methods
void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

// Getter methods
string ItemToPurchase::GetName() const {
    return itemName;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}