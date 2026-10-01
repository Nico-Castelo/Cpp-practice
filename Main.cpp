#include <algorithm>
#include <iostream>
#include <vector>

#include "Lambdas/Unit.h"

int main()
{
    /*std::vector<Unit> Units = {
        Unit("Unit1", 100.0f, 25.0f),
        Unit("Unit2", 100.0f, 10.0f),
        Unit("Unit3", 100.0f, 50.0f),
    };
    
    float MinAttack = 20.0f;
    
    auto FoundIt = std::find_if(Units.begin(), Units.end(),
        [MinAttack](const Unit& u)
        {
            return u.GetDamage() > MinAttack;
        });
    
    if (FoundIt != Units.end())
    {
        std::cout << "Attack unit with more than MinAttack: " << FoundIt->GetName() << "\n";
    }
    
    auto AliveCount = std::count_if(Units.begin(), Units.end(),
        [](const Unit& u)
        {
            return u.GetHealth() > 0;
        });
    
    std::cout << "Units alive: " << AliveCount << "\n";
    
    float TotalAttack = 0.0f;
    
    std::for_each(Units.begin(), Units.end(),
        [&TotalAttack](const Unit& u)
        {
            TotalAttack += u.GetDamage();
        });
    
    std::cout << "Total damage: " << TotalAttack << "\n";
    
    std::sort(Units.begin(), Units.end(),
        [](const Unit& a, const Unit& b)
        {
            return a.GetHealth() > b.GetHealth();
        });
    
    for (const Unit& u : Units)
    {
        std::cout << "  " << u.GetName() << " (" << u.GetHealth() << ")\n";
    }
    
    int KillCount = 0;

    for (Unit& unit : Units)
    {
        unit.OnDeath = [&KillCount](const Unit& u)
        {
            std::cout << u.GetName() << " has died\n";
            ++KillCount;
        };
    }

    for (Unit& unit : Units)
    {
        unit.TakeDamage(60.0f);
        unit.TakeDamage(60.0f);
        unit.TakeDamage(60.0f);   // already dead: OnDeath is not called again
    }

    std::cout << "Kill count: " << KillCount << "\n";*/
    
    

    return 0;
}
