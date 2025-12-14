#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(std::string itemName, int itemPrice, int itemQuantity);

    void SetName(std::string name);
    void SetPrice(int price);
    void SetQuantity(int quantity);

    std::string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;

private:
    std::string itemName;
    int itemPrice;
    int itemQuantity;
};

#endif