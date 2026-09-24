#include "Bow.h"

#include <iostream>

Bow::Bow(const std::string& name, float damage)
    : Weapon(name, damage)
{
    std::cout << GetName() << " created\n";
}

Bow::~Bow()
{
    std::cout << GetName() << " destroyed\n";
}

void Bow::Use() const
{
    std::cout << GetName() << " shoots\n";
}
