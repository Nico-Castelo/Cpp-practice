#include <iostream>
#include <memory>
#include <vector>

#include "Items/Bow.h"
#include "Items/Sword.h"
#include "Items/Weapon.h"


void PrintWeapon(const Weapon& weapon)
{
    std::cout << "Weapon: " << weapon.GetName() << " Damage: " << weapon.GetDamage() << "\n";
}

int main()
{
    std::vector<std::unique_ptr<Weapon>> Weapons;
    
    Weapons.push_back(std::make_unique<Sword>("Katana", 25.0f));
    Weapons.push_back(std::make_unique<Bow>("ElvenBow", 10.0f));

    for (std::unique_ptr<Weapon>& Weapon : Weapons)
    {
        Weapon->Use();
    }
    
    return 0;
}
