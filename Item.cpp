#include "Item.h"

Item::Item(int id, float weight)
    : Id(id)
    , Weight(weight)
{
}

int Item::Getid() const
{
    return Id;
}

float Item::GetWeight() const
{
    return Weight;
}
