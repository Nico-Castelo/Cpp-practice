#pragma once
#include <vector>

#include "Item.h"

class Inventory
{
public:
    
    void AddItem(const Item& item);
    
    float GetTotalWeight() const;
    
    const Item* FindItemById(int Id) const;
    
    bool RemoveItemById(int Id);
    
private:
    
    std::vector<Item> Items;
};
