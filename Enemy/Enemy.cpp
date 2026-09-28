#include "Enemy.h"

#include <iostream>

#include "../Player/Player.h"

Enemy::~Enemy()
{
    std::cout << "Enemy destroyed\n";
}

void Enemy::SetTarget(std::weak_ptr<Player> NewTarget)
{
    Target = NewTarget;
}

void Enemy::Attack()
{
    if (std::shared_ptr<Player> Locked = Target.lock())
    {
        std::cout << "Attacks: " << Locked->GetName() << "\n";
    }
    else
    {
        std::cout << "No target\n"; 
    }
}
