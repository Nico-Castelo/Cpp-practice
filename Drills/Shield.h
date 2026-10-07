#pragma once

class Shield
{
public:
    
    explicit Shield(float InDurability);
    
    virtual ~Shield();
    
    float GetDurability() const { return Durability; }
    
    bool IsBroken() const { return Durability <= 0.0f; }
    
    virtual float Absorb(float damage);


private:
    
    float Durability = 0.0f;
};
