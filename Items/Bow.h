#pragma once
#include "Weapon.h"

class Bow : public Weapon
{
public:
    
     Bow(const std::string& name, float damage);
     
     ~Bow() override;
     
     void Use() const override;
};
