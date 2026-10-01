#include "FireMage.h"

#include "CombatTypes.h"

FireMage::FireMage(const std::string& name, float health, float healthmax)
    : Combatant(name, health, healthmax)
{
}

void FireMage::TakeDamage(const HitInfo& hit)
{
    HitInfo Reduced = hit;
    
    if (Reduced.Type == EDamageType::Fire)
    {
        Reduced.Damage *= 0.5f;
    }
    
    Combatant::TakeDamage(Reduced);
}

void FireMage::Attack(Combatant& target)
{
    HitInfo hit;
    hit.Type = EDamageType::Fire;
    hit.Damage = 10.0f;
    hit.bIsCrtical = false;
    
    target.TakeDamage(hit);
}
