#pragma once
#include "Soldier.h"

class Veteran : public Soldier
{
public:
    
    explicit Veteran(const std::string& name);
    
    float GetDamage() const override { return 20.0f; }

};
