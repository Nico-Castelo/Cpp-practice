#include "ContainerExamples.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Which one to use?
//   vector          -> a list: iterate all of them, or access by position (V[3])
//   unordered_map   -> key -> value: "how much is X?"        (fast, no order)
//   map             -> key -> value, sorted by key            (slower, ordered)
//   unordered_set   -> only keys, no duplicates: "is X in?"  (fast, no order)
//   set             -> only keys, sorted                      (slower, ordered)

void RunContainerExamples()
{
    // ------------------------------------------------------------------
    // 1. vector: a list in order
    // ------------------------------------------------------------------
    std::cout << "1. vector\n";

    std::vector<std::string> Party = { "Wolf", "Emma" };
    Party.reserve(10);                   // reserve memory up front: no reallocations until 10
    Party.push_back("Kuro");             // add at the end

    std::cout << "  Size: " << Party.size() << ", first: " << Party[0] << "\n";

    Party.erase(Party.begin() + 1);      // remove by position (index 1 = "Emma")

    for (const std::string& Member : Party)
    {
        std::cout << "  " << Member << "\n";
    }

    // ------------------------------------------------------------------
    // 2. unordered_map: key -> value, search by key without iterating
    // ------------------------------------------------------------------
    std::cout << "2. unordered_map\n";

    std::unordered_map<std::string, int> Ammo;   // item name -> count

    Ammo["Arrows"] = 20;                 // insert or overwrite
    Ammo["Bombs"] = 3;
    Ammo["Arrows"] += 5;                 // modify an existing value: 25

    // contains: only asks, never modifies (C++20)
    if (Ammo.contains("Arrows"))
    {
        std::cout << "  Has arrows\n";
    }

    // find: read the value WITHOUT creating anything
    auto It = Ammo.find("Bombs");
    if (It != Ammo.end())                // found?
    {
        std::cout << "  " << It->first << ": " << It->second << "\n";   // first = key, second = value
    }

    Ammo.erase("Bombs");                 // remove by key

    // ------------------------------------------------------------------
    // 3. The [] trap: reading with [] CREATES the key if it doesn't exist
    // ------------------------------------------------------------------
    std::cout << "3. The [] trap\n";

    std::cout << "  Size before: " << Ammo.size() << "\n";   // 1
    int Darts = Ammo["Darts"];                                // "Darts" didn't exist -> created with 0
    std::cout << "  Darts: " << Darts << ", size after: " << Ammo.size() << "\n";   // 2: modified by reading!

    // ------------------------------------------------------------------
    // 4. Iterating a map: each element is a pair (key, value)
    // ------------------------------------------------------------------
    std::cout << "4. Iterating\n";

    for (const auto& Pair : Ammo)                   // classic way
    {
        std::cout << "  " << Pair.first << ": " << Pair.second << "\n";
    }

    for (const auto& [Name, Count] : Ammo)          // C++17: names for key and value (more readable)
    {
        std::cout << "  " << Name << " = " << Count << "\n";
    }

    // Never rely on the order of an unordered_map: it can change

    // ------------------------------------------------------------------
    // 5. map: same syntax, but sorted by key
    // ------------------------------------------------------------------
    std::cout << "5. map (sorted)\n";

    std::map<std::string, int> Leaderboard;         // player name -> score (names don't repeat)
    Leaderboard["Wolf"] = 1200;
    Leaderboard["Emma"] = 900;
    Leaderboard["Kuro"] = 1500;

    for (const auto& [Player, Score] : Leaderboard) // always alphabetical: Emma, Kuro, Wolf
    {
        std::cout << "  " << Player << ": " << Score << "\n";
    }

    // Keys are unique: the same key again OVERWRITES
    Leaderboard["Wolf"] = 2000;
    std::cout << "  Wolf now: " << Leaderboard["Wolf"] << ", size: " << Leaderboard.size() << "\n";   // still 3

    // ------------------------------------------------------------------
    // 6. unordered_set: only keys, no duplicates. "Is X in?"
    // ------------------------------------------------------------------
    std::cout << "6. unordered_set\n";

    std::unordered_set<std::string> UnlockedSkills;
    UnlockedSkills.insert("Mikiri Counter");
    UnlockedSkills.insert("Shinobi Eyes");
    UnlockedSkills.insert("Mikiri Counter");        // already there: nothing happens

    std::cout << "  Size: " << UnlockedSkills.size() << "\n";   // 2

    if (UnlockedSkills.contains("Mikiri Counter"))
    {
        std::cout << "  Mikiri Counter unlocked\n";
    }

    UnlockedSkills.erase("Shinobi Eyes");

    // ------------------------------------------------------------------
    // 7. set: only keys, sorted
    // ------------------------------------------------------------------
    std::cout << "7. set (sorted)\n";

    std::set<int> VisitedAreas = { 5, 1, 3, 1 };    // the duplicate 1 is ignored

    for (int Area : VisitedAreas)                   // always sorted: 1, 3, 5
    {
        std::cout << "  Area " << Area << "\n";
    }
}
