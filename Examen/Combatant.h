#pragma once
#include <functional>
#include <string>

struct HitInfo;

class Combatant
{
public:
    
    Combatant(const std::string& name, float health, float healthmax);
    
    virtual ~Combatant();
    
    virtual void TakeDamage(const HitInfo& hit);
    
    virtual void Attack(Combatant& target) = 0;
    
    std::function<void(const Combatant&)> OnDeath;
    
    const std::string& GetName() const { return Name; }
    
    float GetHealth() const { return Health; }
    
    float GetMaxHealth() const { return MaxHealth; }
    
    bool IsAlive() const { return Health > 0; }
    
private:
    
    std::string Name;
    
    float Health;
    
    float MaxHealth;
};
