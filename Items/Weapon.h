#pragma once
#include <string>

class Weapon
{
public:
    
    explicit Weapon(const std::string& name, float damage);
    
    virtual ~Weapon();
    
    const std::string& GetName() const { return Name; }
    
    float GetDamage() const { return Damage; }
    
    virtual void Use() const;
    
    void SetName(const std::string& name);
    
private:
    
    std::string Name;
    
    float Damage = 0.0f;
};
