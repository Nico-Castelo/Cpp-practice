#pragma once

class Weapon
{
public:
    
    Weapon(int InDamage, int InMaxDurability);
    
    void PrintStats() const;
    
private:
    
    int Damage;
    
    const int MaxDurability;
};
