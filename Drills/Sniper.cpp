#include "Sniper.h"

#include <iostream>

#include "Soldier.h"

void Sniper::SetTarget(std::weak_ptr<Soldier> target)
{
    Target = target;
}

void Sniper::Shoot(float damage)
{
    if (std::shared_ptr<Soldier> LockedSoldier = Target.lock())
    {
        if (LockedSoldier->IsAlive())
        {
            LockedSoldier->TakeDamage(damage);
            std::cout << "Shooting: " << LockedSoldier->GetName() << "\n";
        }
        else
        {
            Target.reset();
            std::cout << "Target down\n";
        }
    }
    else
    {
        std::cout << "No Target\n";
    }
}
