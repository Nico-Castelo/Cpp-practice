#include "Weapon.h"

#include <iostream>

Weapon::Weapon(const std::string& name, float damage)
    : Name(name)
    , Damage(damage)
{
    std::cout << "Weapon: " << Name << " has been created\n";
}

Weapon::~Weapon()
{
    std::cout << "Weapon: " << Name << " has been destroyed\n";
}

void Weapon::Use() const
{
    std::cout << Name << " Attacks\n";
}

void Weapon::SetName(const std::string& name) 
{
    Name = name;
}
