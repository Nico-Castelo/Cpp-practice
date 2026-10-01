#include "Arena.h"

#include <iostream>
#include <algorithm>

#include "Combatant.h"

void Arena::AddCombatant(std::unique_ptr<Combatant> combatant)
{
    Combatants.push_back(std::move(combatant));
}

Combatant* Arena::FindTargetFor(const Combatant& attacker)
{
    auto FoundIterator = std::find_if(Combatants.begin(), Combatants.end(),
        [&attacker](const std::unique_ptr<Combatant>& c)
        {
            return c->IsAlive() && c.get() != &attacker;
        });
    
    if (FoundIterator != Combatants.end())
    {
        return FoundIterator->get();
    }
    
    return nullptr;
}

int Arena::CountAlive() const
{
    auto AliveCount = std::count_if(Combatants.begin(), Combatants.end(),
        [](const std::unique_ptr<Combatant>& c)
        {
            return c->IsAlive();
        });
    
    return static_cast<int>(AliveCount);
}

void Arena::RunRound()
{
    for (const std::unique_ptr<Combatant>& c : Combatants)
    {
        if (!c->IsAlive()) continue;
        
        Combatant* Target = FindTargetFor(*c);
        if (Target)
        {
            c->Attack(*Target);
        }
    }
}
