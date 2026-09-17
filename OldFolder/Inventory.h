#pragma once
#include <memory>
#include <vector>

class Item;

class Inventory
{
public:
    
    void AddItem(std::unique_ptr<Item> item);
    
    const Item& GetItemById(int id) const;    
    
    void RemoveItemsHeavierThan(float maxWeight);
    
private:
    
    std::vector<std::unique_ptr<Item>> Items;
};
