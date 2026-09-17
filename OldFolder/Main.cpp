#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

#include "Fireball.h"
#include "Gate.h"
#include "Inventory.h"
#include "Item.h"
#include "Sword.h"
#include "Weapon.h"

std::unique_ptr<Ability> CreateAbility()
{
    std::unique_ptr<Ability> F = std::make_unique<Fireball>();
    return F;
}

void PreviewAbility(const Ability& ability)
{
    ability.Execute();
}

bool IsNegative(int Value)
{
    return Value < 0;
}

bool IsLarge(int Value)
{
    return Value > 10;
}

template<typename T>
T ChooseLarger(const T& A, const T& B)
{
    if (A > B)
    {
        return A;
    }
    
    return B;
}

template<typename T>
bool AreEqual(const T& A, const T& B)
{
    return A == B;
}

enum class WeaponType
{
    Sword,
    Bow,
    Staff
};

int main()
{
    /*{
        std::unique_ptr<Ability> f = CreateAbility();
    
        PreviewAbility(*f);
        
        Ability PlainAbility;
        
        Fireball* AsFireball = dynamic_cast<Fireball*>(&PlainAbility);
        
        if (!AsFireball)
        {
            std::cout << "Not a Fireball!\n";
        }
    }
    
    std::vector<int> Damage{3, 7, 10, 2};
    
    int MinimumDamage = 5;
    
    std::erase_if(Damage, [MinimumDamage](int Value)
    {
        return Value < MinimumDamage;
    });
    
    for (int damage : Damage)
    {
        std::cout << damage << "\n";
    }

    
    const Weapon w(25, 100);
    w.PrintStats();
    WeaponType SwordType = WeaponType::Sword;
    
    if (SwordType == WeaponType::Sword)
    {
        std::cout << "Sword selected\n";
    }
    
    auto Result = ChooseLarger<float>(10, 3.5f);
    std::cout << Result << "\n";
    
    int Limit = 5;

    auto IsBelowLimit = [&Limit](int Value)
    {
        return Value < Limit;
    };

    Limit = 10;

    std::cout << IsBelowLimit(7) << "\n";
    
    float Stamina = 42.75f;
    
    int DisplayedStamina = static_cast<int>(Stamina);
    
    std::cout << Stamina << "\n";
    std::cout << DisplayedStamina << "\n";
    
    std::vector<int> Values{4, -2, 7, -5, 10, 1};
    int Minimum = 3;
    
    auto IsBelowMinimum = [Minimum](int Value)
    {
        return Value < Minimum;
    };
    
    Minimum = 8;
    
    std::erase_if(Values, IsBelowMinimum);
    
    for (auto Value : Values)
    {
        std::cout << Value << "\n";
    }
    
    
    const Gate g(7, GateState::Locked);
    
    std::cout << g.IsLocked();*/
    
    
    /*bool EqualInt = AreEqual(4, 4);
    bool EqualFloat = AreEqual(2.5f, 3.0f);
    
    std::cout << EqualInt << "\n";
    std::cout << EqualFloat << "\n";
    
    auto Owner = std::make_unique<Sword>();
    Item* ItemBorrowed = Owner.get();
    Sword* SwordPointer = dynamic_cast<Sword*>(ItemBorrowed);
    
    if (SwordPointer)
    {
        std::cout << SwordPointer << " Is valid\n";
    }*/
    
    Inventory inventory;

    inventory.AddItem(std::make_unique<Item>(1, 5.0f));
    inventory.AddItem(std::make_unique<Item>(2, 15.0f));
    inventory.AddItem(std::make_unique<Item>(3, 30.0f));

    const Item& item = inventory.GetItemById(2);

    inventory.RemoveItemsHeavierThan(20.0f);
    
    
    return 0;
}
