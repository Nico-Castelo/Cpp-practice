#pragma once
#include "Combatant.h"

class FireMage : public Combatant
{
public:
    
    FireMage(const std::string& name, float health, float healthmax);

    ~FireMage() override = default;

    void TakeDamage(const HitInfo& hit) override;
    
    void Attack(Combatant& target) override;
};
