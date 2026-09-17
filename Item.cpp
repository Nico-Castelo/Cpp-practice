#include "Item.h"

#include <iostream>

Item::Item(int id, float weight)
    : Id(id)
    , Weight(weight)
{
}

int Item::GetId() const
{
    return Id;
}

float Item::GetWeight() const
{
    return Weight;
}
