#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
    
    explicit Sword(const std::string& name, float damage);
    
    ~Sword() override;
    
    void Use() const override;
};
