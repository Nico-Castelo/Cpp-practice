#include "Medic.h"

#include <iostream>

#include "Soldier.h"

void Medic::SetPatient(std::weak_ptr<Soldier> patient)
{
    Patient = patient;
}

void Medic::Heal()
{
    if (auto LockedPatient = Patient.lock())
    {
        std::cout << "Healing " << LockedPatient->GetName() << "\n";
    }
    else
    {
        std::cout << "No patient to heal.\n";
    }
    
}
