#pragma once
#include <memory>

class Soldier;

class Medic
{
public:
    
    void SetPatient(std::weak_ptr<Soldier> patient);
    
    void Heal();
    
private:
    
    std::weak_ptr<Soldier> Patient;
};
