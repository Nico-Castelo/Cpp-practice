#include "StructExamples.h"

#include <cmath>      // std::sqrt
#include <iostream>
#include <string>
#include <vector>

namespace StructExample
{
    // 1. Plain data: everything public, with default values
    struct HitInfo
    {
        float Damage = 0.0f;
        bool bIsCritical = false;
        std::string AttackerName;
    };

    // 2. A struct can have functions too: it's a class that is public by default
    struct Vec2
    {
        float X = 0.0f;
        float Y = 0.0f;

        float Length() const { return std::sqrt(X * X + Y * Y); }
    };

    // 3. The same idea written as a class: only the default access changes
    class Vec2AsClass
    {
    public:              // without this line, X and Y would be private
        float X = 0.0f;
        float Y = 0.0f;
    };

    // 4. Passing structs: by const& to read without copying
    void PrintHit(const HitInfo& hit)
    {
        std::cout << "  " << hit.AttackerName << " hits for " << hit.Damage
                  << (hit.bIsCritical ? " (critical)" : "") << "\n";
    }

    // 5. Returning a struct by value is fine (the compiler avoids the copy)
    HitInfo MakeCritical(const std::string& attacker, float damage)
    {
        return { damage * 2.0f, true, attacker };
    }
}

using StructExample::HitInfo;
using StructExample::Vec2;
using StructExample::Vec2AsClass;
using StructExample::PrintHit;
using StructExample::MakeCritical;

void RunStructExamples()
{
    // ------------------------------------------------------------------
    // 1. Ways to initialize
    // ------------------------------------------------------------------
    std::cout << "1. Initialize\n";

    HitInfo A;                                                    // all default values
    HitInfo B{ 25.0f, true, "Wolf" };                             // in declaration order
    HitInfo C{ .Damage = 40.0f, .AttackerName = "Genichiro" };   // C++20: by name. Skipped ones keep their default

    PrintHit(A);
    PrintHit(B);
    PrintHit(C);

    // Note: if you add a constructor to a struct, the {...} by members above stops working

    // ------------------------------------------------------------------
    // 2. Members are public: read and write them directly
    // ------------------------------------------------------------------
    std::cout << "2. Direct access\n";

    B.Damage += 5.0f;
    PrintHit(B);

    // ------------------------------------------------------------------
    // 3. Returning a struct from a function
    // ------------------------------------------------------------------
    std::cout << "3. Return by value\n";

    HitInfo Crit = MakeCritical("Emma", 10.0f);
    PrintHit(Crit);

    // ------------------------------------------------------------------
    // 4. Structs in a vector (very common: a list of hits, spawns, items...)
    // ------------------------------------------------------------------
    std::cout << "4. In a vector\n";

    std::vector<HitInfo> Hits = {
        { 10.0f, false, "Soldier" },
        { 30.0f, true, "Wolf" },
    };

    for (const HitInfo& Hit : Hits)
    {
        PrintHit(Hit);
    }

    // ------------------------------------------------------------------
    // 5. A struct with a function, and the class version
    // ------------------------------------------------------------------
    std::cout << "5. Struct with a function\n";

    Vec2 V{ 3.0f, 4.0f };
    std::cout << "  Length of (3, 4): " << V.Length() << "\n";   // 5

    Vec2AsClass W{ 1.0f, 2.0f };                                   // works because X and Y are public
    std::cout << "  Class version: (" << W.X << ", " << W.Y << ")\n";
}
