#pragma once
#include "Combatant.h"

class Samurai : public Combatant
{
public:

    explicit Samurai(const std::string& name, float health, float healthmax);

    ~Samurai() override;

    void TakeDamage(const HitInfo& hit) override;
    
    void Attack(Combatant& target) override;
    
    int GetComboCount() const { return ComboIndex; }
    
private:
    
    int ComboIndex = 0;
};
