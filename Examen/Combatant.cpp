#include "Combatant.h"

#include <iostream>
#include <algorithm>

#include "CombatTypes.h"

Combatant::Combatant(const std::string& name, float health, float healthmax)
    : Name(name)
    , Health(health)
    , MaxHealth(healthmax)
{
    std::cout << "Combatant: " << Name << " has been created\n";
}

Combatant::~Combatant()
{
    std::cout << "Combatant: " << Name << " has been destroyed\n";
}

void Combatant::TakeDamage(const HitInfo& hit)
{
    if (IsAlive())
    {
        Health = std::max(Health - hit.Damage, 0.0f);
        
        if (OnDeath && !IsAlive())
        {
            OnDeath(*this);
        }
    }
}
