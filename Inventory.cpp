#include "Inventory.h"

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
