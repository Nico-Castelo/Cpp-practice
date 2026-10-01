#pragma once
#include <memory>
#include <vector>

class Combatant;

class Arena
{
public:
    
    void AddCombatant(std::unique_ptr<Combatant> combatant);
    
    Combatant* FindTargetFor(const Combatant& attacker);
    
    int CountAlive() const;
    
    void RunRound();
    
    const std::vector<std::unique_ptr<Combatant>>& GetCombatants() const { return Combatants; }
    
private:
    
    std::vector<std::unique_ptr<Combatant>> Combatants;
};
