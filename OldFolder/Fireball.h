#pragma once
#include <memory>

#include "Ability.h"

class Fireball : public Ability
{
public:
    
    Fireball();
    
    ~Fireball() override;
    
    void Execute() const override;
    
    
    
};
