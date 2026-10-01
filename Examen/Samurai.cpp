#include "Samurai.h"

#include "CombatTypes.h"


Samurai::Samurai(const std::string& name, float health, float healthmax)
    : Combatant(name, health, healthmax)
{
}

Samurai::~Samurai()
{
    
}

void Samurai::TakeDamage(const HitInfo& hit)
{
    Combatant::TakeDamage(hit);
}

void Samurai::Attack(Combatant& target)
{
    HitInfo hit;
    hit.Type = EDamageType::Physical;
    hit.Damage = 25.0f;

    if (ComboIndex == 2)
    {
        hit.Damage *= 2.0f;
        hit.bIsCrtical = true;
        ComboIndex = 0;
    }
    else
    {
        ++ComboIndex;
    }

    target.TakeDamage(hit);  
}
