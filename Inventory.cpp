#include "Inventory.h"

#include <algorithm>
#include <iostream>

void Inventory::AddItem(const Item& item)
{
    Items.push_back(item);
}

float Inventory::GetTotalWeight() const
{
    float TotalWeight = 0.0f;
    
    for (const Item& item : Items)
    {
        TotalWeight += item.GetWeight();
    }
    
    return TotalWeight;
}

const Item* Inventory::FindItemById(int Id) const
{
    // for (const Item& ItemToCheck : Items)
    // {
    //     if (ItemToCheck.GetId() == Id)
    //     {
    //         return &ItemToCheck;
    //     }
    // }
    //
    // return nullptr;
    
    const auto FoundIterator = std::find_if(Items.cbegin(), Items.cend(),
        [Id](const Item& ItemToCheck)
        {
            return ItemToCheck.GetId() == Id;
        });

    if (FoundIterator != Items.cend())
    {
        return &(*FoundIterator);
    }

    return nullptr;
}

bool Inventory::RemoveItemById(int Id)
{
    const auto FoundIterator = std::find_if(Items.cbegin(), Items.cend(),
        [Id](const Item& ItemToCheck)
    {
            return ItemToCheck.GetId() == Id;
    });
    
    if (FoundIterator == Items.cend())
    {
        return false;
    }
    
    Items.erase(FoundIterator);
    return true;
}
