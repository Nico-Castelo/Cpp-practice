#include "Weapon.h"

#include <iostream>

Weapon::Weapon(int InDamage, int InMaxDurability)

    : Damage(InDamage)
    , MaxDurability(InMaxDurability)
{
}

void Weapon::PrintStats() const
{
    std::cout << "Damage: " << Damage << "\n";
    std::cout << "MaxDurability: " << MaxDurability << "\n";
}
