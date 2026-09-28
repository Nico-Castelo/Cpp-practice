#include "Unit.h"
#include <algorithm>

Unit::Unit(const std::string& name, float health, float damage)
    : Name(name)
    , Health(health)
    , Damage(damage)
{
}

void Unit::TakeDamage(float amount)
{
    if (IsAlive())
    {
        Health = std::max(Health - amount, 0.0f);
        
        if (OnDeath && !IsAlive())
        {
            OnDeath(*this);
        }
    }
}
