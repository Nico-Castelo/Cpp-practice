#pragma once
#include <vector>

#include "Item.h"

class Inventory
{
public:
    
    void AddItem(const Item& item);
    
    float GetTotalWeight() const;
    
private:
    
    std::vector<Item> Items;
};
