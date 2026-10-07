#include "Shield.h"

Shield::Shield(float InDurability)
    : Durability(InDurability)
{
    
}

Shield::~Shield()
{
    
}

float Shield::Absorb(float damage)
{
    if (IsBroken())
    {
        return damage;
    }
    
    if (Durability >= damage)
    {
        Durability -= damage;
        return 0.0f;
    }
    else
    {
        float Overflow = damage - Durability;
        Durability = 0.0f;
        
        return Overflow;
    }
}
