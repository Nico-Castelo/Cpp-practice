#include "AlgorithmExamples.h"

#include <algorithm>   // any_of, all_of, none_of, min/max_element, transform, find, remove_if, sort...
#include <cmath>       // std::abs
#include <iostream>
#include <iterator>    // std::back_inserter
#include <numeric>     // std::accumulate (NOT in <algorithm>)
#include <string>
#include <vector>

// Almost every algorithm has the same shape:
//   std::algorithm(Container.begin(), Container.end(), lambda);
//                  from               to              what to do / what to check

namespace AlgorithmExample
{
    class Enemy
    {
    public:
        Enemy(const std::string& name, float health, float positionX, bool bSpotted)
            : Name(name)
            , Health(health)
            , PositionX(positionX)
            , bHasSpottedPlayer(bSpotted)
        {
        }

        const std::string& GetName() const { return Name; }
        float GetHealth() const { return Health; }
        bool IsAlive() const { return Health > 0.0f; }
        bool HasSpottedPlayer() const { return bHasSpottedPlayer; }
        float DistanceTo(float x) const { return std::abs(PositionX - x); }   // 1D to keep it simple

    private:
        std::string Name;
        float Health = 100.0f;
        float PositionX = 0.0f;
        bool bHasSpottedPlayer = false;
    };
}

using AlgorithmExample::Enemy;

void RunAlgorithmExamples()
{
    std::vector<Enemy> Enemies = {
        Enemy("Ashina Soldier", 40.0f, 30.0f, false),
        Enemy("Genichiro", 150.0f, 80.0f, true),
        Enemy("Bandit", 0.0f, 10.0f, false),
        Enemy("Samurai General", 90.0f, 55.0f, false),
    };

    // ------------------------------------------------------------------
    // 1. any_of / all_of / none_of: yes-or-no questions about the whole container.
    //    They stop as soon as they know the answer (count_if always goes through everything).
    // ------------------------------------------------------------------
    std::cout << "1. any_of / all_of / none_of\n";

    bool bAnyAlive = std::any_of(Enemies.begin(), Enemies.end(),
        [](const Enemy& e) { return e.IsAlive(); });

    bool bAllDead = std::all_of(Enemies.begin(), Enemies.end(),
        [](const Enemy& e) { return !e.IsAlive(); });

    bool bUndetected = std::none_of(Enemies.begin(), Enemies.end(),
        [](const Enemy& e) { return e.HasSpottedPlayer(); });

    std::cout << std::boolalpha;   // print bools as true/false instead of 1/0
    std::cout << "  Any alive: " << bAnyAlive << ", all dead: " << bAllDead
              << ", undetected: " << bUndetected << "\n";

    // ------------------------------------------------------------------
    // 2. min_element / max_element: returns an ITERATOR (check end() if it can be empty)
    // ------------------------------------------------------------------
    std::cout << "2. min_element / max_element\n";

    std::vector<int> Damages = { 12, 45, 7, 30 };

    auto MaxIt = std::max_element(Damages.begin(), Damages.end());   // simple values: no lambda
    std::cout << "  Highest damage: " << *MaxIt << "\n";             // * gets the value

    // With objects: the lambda answers "is a LESS than b?". Always '<', also for max_element
    float PlayerX = 50.0f;

    auto Closest = std::min_element(Enemies.begin(), Enemies.end(),
        [PlayerX](const Enemy& a, const Enemy& b)
        {
            return a.DistanceTo(PlayerX) < b.DistanceTo(PlayerX);
        });

    if (Closest != Enemies.end())   // an empty vector returns end()
    {
        std::cout << "  Closest enemy: " << Closest->GetName() << "\n";
    }

    auto Strongest = std::max_element(Enemies.begin(), Enemies.end(),
        [](const Enemy& a, const Enemy& b) { return a.GetHealth() < b.GetHealth(); });

    std::cout << "  Most health: " << Strongest->GetName() << "\n";

    // ------------------------------------------------------------------
    // 3. accumulate: reduce everything to ONE value. Lives in <numeric>
    // ------------------------------------------------------------------
    std::cout << "3. accumulate\n";

    int TotalDamage = std::accumulate(Damages.begin(), Damages.end(), 0);   // 0 = initial value
    std::cout << "  Total damage: " << TotalDamage << "\n";                  // 94

    // With objects: the lambda receives (what's accumulated so far, current element)
    float TotalHealth = std::accumulate(Enemies.begin(), Enemies.end(), 0.0f,
        [](float Sum, const Enemy& e) { return Sum + e.GetHealth(); });

    std::cout << "  Total health: " << TotalHealth << "\n";

    // Trap: the INITIAL VALUE decides the result type
    std::vector<float> Multipliers = { 1.5f, 1.5f };
    float Wrong = std::accumulate(Multipliers.begin(), Multipliers.end(), 0);      // int: 1 + 1 = 2
    float Right = std::accumulate(Multipliers.begin(), Multipliers.end(), 0.0f);   // float: 3.0
    std::cout << "  With 0: " << Wrong << ", with 0.0f: " << Right << "\n";

    // ------------------------------------------------------------------
    // 4. transform: convert each element into something else
    // ------------------------------------------------------------------
    std::cout << "4. transform\n";

    // Option A: the destination must already have room for every element
    std::vector<float> Healths(Enemies.size());

    std::transform(Enemies.begin(), Enemies.end(), Healths.begin(),
        [](const Enemy& e) { return e.GetHealth(); });

    // Option B: back_inserter does a push_back for each result (start from an empty vector)
    std::vector<std::string> Names;

    std::transform(Enemies.begin(), Enemies.end(), std::back_inserter(Names),
        [](const Enemy& e) { return e.GetName(); });

    for (size_t i = 0; i < Names.size(); ++i)
    {
        std::cout << "  " << Names[i] << ": " << Healths[i] << "\n";
    }

    // Transform in place: destination = the same vector
    std::transform(Damages.begin(), Damages.end(), Damages.begin(),
        [](int d) { return d * 2; });   // double every damage
    std::cout << "  Doubled first damage: " << Damages[0] << "\n";   // 24

    // ------------------------------------------------------------------
    // 5. find: search for an exact VALUE (no lambda). find_if searches with a condition
    // ------------------------------------------------------------------
    std::cout << "5. find\n";

    std::vector<std::string> Unlocked = { "Mikiri Counter", "Shinobi Eyes" };

    auto Found = std::find(Unlocked.begin(), Unlocked.end(), "Mikiri Counter");
    if (Found != Unlocked.end())
    {
        std::cout << "  Found: " << *Found << "\n";
    }

    // ------------------------------------------------------------------
    // 6. Erasing: the remove_if trap
    // ------------------------------------------------------------------
    std::cout << "6. remove_if vs erase_if\n";

    std::vector<int> Values = { 1, 0, 2, 0, 3 };

    // remove_if does NOT erase: it moves the kept elements to the front
    // and returns where the leftovers begin. The size stays the same
    auto NewEnd = std::remove_if(Values.begin(), Values.end(), [](int v) { return v == 0; });
    std::cout << "  After remove_if, size is still: " << Values.size() << "\n";   // 5

    // Old C++: erase the leftovers yourself ("erase-remove")
    Values.erase(NewEnd, Values.end());
    std::cout << "  After erase: " << Values.size() << "\n";                       // 3

    // C++20: erase_if does both in one step. It takes the CONTAINER, not begin/end
    std::erase_if(Enemies, [](const Enemy& e) { return !e.IsAlive(); });
    std::cout << "  Enemies alive after erase_if: " << Enemies.size() << "\n";     // 3

    // ------------------------------------------------------------------
    // 7. Recap of the ones you already know, together
    // ------------------------------------------------------------------
    std::cout << "7. Recap\n";

    std::sort(Enemies.begin(), Enemies.end(),                            // sort: most health first
        [](const Enemy& a, const Enemy& b) { return a.GetHealth() > b.GetHealth(); });

    auto FirstWeak = std::find_if(Enemies.begin(), Enemies.end(),       // find_if: first matching
        [](const Enemy& e) { return e.GetHealth() < 100.0f; });

    auto WeakCount = std::count_if(Enemies.begin(), Enemies.end(),      // count_if: how many
        [](const Enemy& e) { return e.GetHealth() < 100.0f; });

    if (FirstWeak != Enemies.end())
    {
        std::cout << "  First weak: " << FirstWeak->GetName() << ", weak count: " << WeakCount << "\n";
    }

    std::for_each(Enemies.begin(), Enemies.end(),                       // for_each: do something with each
        [](const Enemy& e) { std::cout << "  " << e.GetName() << "\n"; });
}
