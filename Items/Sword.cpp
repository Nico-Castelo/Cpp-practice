#include "Sword.h"

#include <iostream>

Sword::Sword(const std::string& name, float damage)
    : Weapon(name, damage)
{
    std::cout << GetName() << " created\n";
}

Sword::~Sword()
{
    std::cout << GetName() << " destroyed\n";
}

void Sword::Use() const
{
    std::cout << GetName() << " cuts\n";
}
