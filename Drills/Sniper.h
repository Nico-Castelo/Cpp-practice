#pragma once
#include <memory>

class Soldier;

class Sniper
{
public:
    
    void SetTarget(std::weak_ptr<Soldier> target);
    
    void Shoot(float damage);
    
private:
    
    std::weak_ptr<Soldier> Target;
};
