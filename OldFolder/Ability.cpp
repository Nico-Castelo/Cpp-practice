#include "Ability.h"

#include <iostream>

Ability::Ability()
{
    std::cout << "Se ha construido la ability\n";
}

Ability::~Ability()
{
    std::cout << "Se ha destruido la ability\n";
}

void Ability::Execute() const
{
    std::cout << "Ability ejecutada\n";
}
