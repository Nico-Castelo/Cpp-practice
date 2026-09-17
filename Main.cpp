
#include <iostream>

#include "Inventory.h"
#include "Item.h"

void PrintItem(const Item& item)
{
    std::cout << "Id: " << item.GetId() << "\n";
    std::cout << "Weight: " << item.GetWeight() << "\n";
}

int main()
{
    const Item potion(1, 0.5);
    
    Item PotionCopy = potion;
    
    const Item& potionReference = potion;
    
    PrintItem(potion);
    PrintItem(PotionCopy);
    PrintItem(potionReference);
    
    Inventory items;
    
    items.AddItem(potion);
    items.AddItem(PotionCopy);
    
    std::cout << "Total weight: " << items.GetTotalWeight() << "\n";
    
    return 0;
}
