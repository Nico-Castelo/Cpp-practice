#include "Inventory.h"

#include <stdexcept>

#include "Item.h"

void Inventory::AddItem(std::unique_ptr<Item> item)
{
    Items.push_back(std::move(item));
}

const Item& Inventory::GetItemById(int id) const
{
    auto it = std::find_if(
        Items.begin(),
        Items.end(),
        [id](const std::unique_ptr<Item>& item)
        {
            return item->GetId() == id;
        }
    );

    if (it == Items.end())
    {
        throw std::out_of_range("Item not found");
    }

    return **it;
}

void Inventory::RemoveItemsHeavierThan(float maxWeight)
{
    std::erase_if(
        Items,
        [maxWeight](const std::unique_ptr<Item>& item)
        {
            return item->GetWeight() > maxWeight;
        }
        );
}
