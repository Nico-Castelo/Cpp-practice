#include "Item.h"

Item::Item(int id, float weight)
    : Id(id)
    , Weight(weight)
{
}

Item::~Item()
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
