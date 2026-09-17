#include "Fireball.h"

#include <iostream>

Fireball::Fireball()
{
    std::cout << "Fireball creada\n";
}

Fireball::~Fireball()
{
    std::cout << "Fireball destruida\n";
}

void Fireball::Execute() const
{
    std::cout << "Fireball lanzada\n";
}

