#pragma once
#include <functional>
#include <string>

class Unit
{
public:
    
    Unit(const std::string& name, float health, float damage);
    
    const std::string& GetName() const { return Name; }
    
    float GetHealth() const { return Health; }
    
    float GetDamage() const { return Damage; }
    
    bool IsAlive() const { return Health > 0; }
    
    void TakeDamage(float amount);
    
    std::function<void(const Unit&)> OnDeath;
    
private:
    
    std::string Name;
    
    float Health;
    
    float Damage;
};
