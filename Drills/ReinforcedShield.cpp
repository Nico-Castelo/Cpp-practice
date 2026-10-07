#include "ReinforcedShield.h"

ReinforcedShield::ReinforcedShield(float InDurability)
    : Shield(InDurability)
{
}

ReinforcedShield::~ReinforcedShield()
{
    
}

float ReinforcedShield::Absorb(float damage)
{
    float ReducedDamage = damage / 2.0f;
    
    return Shield::Absorb(ReducedDamage);
}
