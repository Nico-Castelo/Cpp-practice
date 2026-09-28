#include "LambdaExamples.h"

#include <algorithm>    // find_if, count_if, sort, for_each
#include <functional>   // std::function
#include <iostream>
#include <string>
#include <utility>      // std::move
#include <vector>

// Small classes for this example only (namespace so they don't clash with yours)
namespace LambdaExample
{
    class Fighter
    {
    public:
        Fighter(const std::string& name, float health)
            : Name(name)
            , Health(health)
        {
        }

        const std::string& GetName() const { return Name; }
        float GetHealth() const { return Health; }
        bool IsAlive() const { return Health > 0.0f; }

        // CALLBACK: stores a function to run later.
        // Signature: returns void, takes a float.
        std::function<void(float)> OnDamaged;

        void TakeDamage(float amount)
        {
            Health -= amount;

            if (OnDamaged)                 // has anyone assigned a lambda?
            {
                OnDamaged(amount);         // run it
            }
        }

    private:
        std::string Name;
        float Health = 100.0f;
    };

    class PoisonTrap
    {
    public:
        // [this]: the lambda uses the object's members (only safe while the object is alive)
        void AttachWithThis(Fighter& target)
        {
            target.OnDamaged = [this](float /*amount*/)   // unnamed parameter: not used
            {
                std::cout << "  [this] extra poison: " << PoisonDamage << "\n";
            };
        }

        // Copy of the member: the lambda carries its own value (doesn't depend on the PoisonTrap)
        void AttachWithCopy(Fighter& target)
        {
            target.OnDamaged = [Damage = PoisonDamage](float /*amount*/)
            {
                std::cout << "  [copy] extra poison: " << Damage << "\n";
            };
        }

    private:
        float PoisonDamage = 5.0f;
    };
}

using LambdaExample::Fighter;
using LambdaExample::PoisonTrap;

void RunLambdaExamples()
{
    std::vector<Fighter> Fighters = {
        Fighter("Wolf", 100.0f),
        Fighter("Genichiro", 0.0f),
        Fighter("Ashina Soldier", 15.0f),
    };

    // ------------------------------------------------------------------
    // 1. Basic lambda stored in a variable
    //    [capture](parameters) { body }
    // ------------------------------------------------------------------
    std::cout << "1. Basic lambda\n";

    auto IsDead = [](const Fighter& f) { return !f.IsAlive(); };

    std::cout << "  Is Genichiro dead? " << IsDead(Fighters[1]) << "\n";

    // ------------------------------------------------------------------
    // 2. Lambda passed directly as an argument (predicate for find_if)
    // ------------------------------------------------------------------
    std::cout << "2. find_if\n";

    auto FoundIt = std::find_if(Fighters.begin(), Fighters.end(),
        [](const Fighter& f) { return !f.IsAlive(); });

    if (FoundIt != Fighters.end())
    {
        std::cout << "  First dead fighter: " << FoundIt->GetName() << "\n";
    }

    // ------------------------------------------------------------------
    // 3. Capture by COPY: a threshold from outside
    // ------------------------------------------------------------------
    std::cout << "3. Capture by copy\n";

    float MinHealth = 20.0f;

    auto LowCount = std::count_if(Fighters.begin(), Fighters.end(),
        [MinHealth](const Fighter& f) { return f.IsAlive() && f.GetHealth() < MinHealth; });

    std::cout << "  Alive with low health: " << LowCount << "\n";

    // ------------------------------------------------------------------
    // 4. Capture by REFERENCE: accumulate into an outside variable
    //    (safe: for_each runs the lambda right away)
    // ------------------------------------------------------------------
    std::cout << "4. Capture by reference\n";

    float TotalHealth = 0.0f;

    std::for_each(Fighters.begin(), Fighters.end(),
        [&TotalHealth](const Fighter& f) { TotalHealth += f.GetHealth(); });

    std::cout << "  Total health: " << TotalHealth << "\n";

    // ------------------------------------------------------------------
    // 5. Copy vs reference: when the value is taken
    // ------------------------------------------------------------------
    std::cout << "5. Copy vs reference\n";

    int Count = 0;
    auto ByCopy = [Count]() { return Count; };   // copy taken NOW (0)
    auto ByRef = [&Count]() { return Count; };   // reads the original
    Count = 5;

    std::cout << "  ByCopy: " << ByCopy() << ", ByRef: " << ByRef() << "\n";

    // ------------------------------------------------------------------
    // 6. sort with a two-parameter lambda (lowest health first)
    // ------------------------------------------------------------------
    std::cout << "6. sort\n";

    std::sort(Fighters.begin(), Fighters.end(),
        [](const Fighter& a, const Fighter& b) { return a.GetHealth() < b.GetHealth(); });

    for (const Fighter& f : Fighters)
    {
        std::cout << "  " << f.GetName() << " (" << f.GetHealth() << ")\n";
    }

    // ------------------------------------------------------------------
    // 7. std::function as a callback: runs LATER
    // ------------------------------------------------------------------
    std::cout << "7. Callback with std::function\n";

    Fighter Wolf("Wolf", 100.0f);

    Wolf.OnDamaged = [](float amount)
    {
        std::cout << "  Wolf takes " << amount << " damage\n";
    };

    Wolf.TakeDamage(25.0f);

    // ------------------------------------------------------------------
    // 8. [this] and copying a member
    // ------------------------------------------------------------------
    std::cout << "8. [this] and member copy\n";

    PoisonTrap Trap;

    Trap.AttachWithThis(Wolf);    // safe as long as Trap exists
    Wolf.TakeDamage(10.0f);

    Trap.AttachWithCopy(Wolf);    // always safe: carries its own copy
    Wolf.TakeDamage(10.0f);

    // ------------------------------------------------------------------
    // 9. Moving something big into the lambda
    // ------------------------------------------------------------------
    std::cout << "9. Move into the lambda\n";

    std::vector<std::string> Names = { "Wolf", "Genichiro", "Emma" };

    auto PrintNames = [List = std::move(Names)]()   // the lambda takes ownership of the vector
    {
        for (const std::string& n : List)
        {
            std::cout << "  " << n << "\n";
        }
    };

    PrintNames();

    // A moved-from object is valid but its contents aren't guaranteed: don't use it again. In practice, empty
    std::cout << "  Names has " << Names.size() << " elements after the move\n";
}
