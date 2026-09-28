#pragma once
#include <memory>


class Player;

class Enemy
{
public:
    
    Enemy() = default;
    
    virtual ~Enemy();
    
    void SetTarget(std::weak_ptr<Player> NewTarget);
    
    void Attack();
    
private:
    
    std::weak_ptr<Player> Target;
};
