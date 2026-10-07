#pragma once
#include "Shield.h"

class ReinforcedShield : public Shield
{
public:
    
    explicit ReinforcedShield(float InDurability);
    
    ~ReinforcedShield() override;
    
    float Absorb(float damage) override;

};
