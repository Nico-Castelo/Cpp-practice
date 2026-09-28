#include "Player.h"

#include <iostream>

Player::Player(const std::string& name)
    : Name(name)
{
    std::cout << "Player: " << Name << " created\n";
}

Player::~Player()
{
    std::cout << "Player: " << Name << " destroyed\n";
}
