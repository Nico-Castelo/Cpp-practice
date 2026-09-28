#include "CastExamples.h"

#include <cmath>      // std::round
#include <iostream>
#include <memory>
#include <vector>

namespace CastExample
{
    // A small hierarchy for dynamic_cast. It needs at least one virtual function
    class Ability
    {
    public:
        virtual ~Ability() = default;
        virtual void Activate() const { std::cout << "  Ability activated\n"; }
    };

    class Fireball : public Ability
    {
    public:
        void Activate() const override { std::cout << "  Fireball cast\n"; }
        void Explode() const { std::cout << "  Fireball explodes (only Fireball has this)\n"; }
    };

    class Dash : public Ability
    {
    public:
        void Activate() const override { std::cout << "  Dash!\n"; }
    };
}

using CastExample::Ability;
using CastExample::Fireball;
using CastExample::Dash;

void RunCastExamples()
{
    // ------------------------------------------------------------------
    // 1. static_cast between numbers
    // ------------------------------------------------------------------
    std::cout << "1. Numbers\n";

    int Health = 75;
    float AsFloat = static_cast<float>(Health);                  // 75.0: nothing is lost
    std::cout << "  int -> float: " << AsFloat << "\n";

    float Speed = 3.7f;
    int Truncated = static_cast<int>(Speed);                     // 3: TRUNCATES, doesn't round
    int Rounded = static_cast<int>(std::round(Speed));           // 4: round first, then convert
    std::cout << "  float -> int: " << Truncated << " (rounded: " << Rounded << ")\n";

    // ------------------------------------------------------------------
    // 2. Trap: integer division
    // ------------------------------------------------------------------
    std::cout << "2. Integer division\n";

    int Kills = 3;
    int Deaths = 2;

    float Bad = Kills / Deaths;                                  // 1: int / int is done first, THEN converted
    float Good = static_cast<float>(Kills) / Deaths;             // 1.5: one float makes it a float division
    std::cout << "  Bad K/D: " << Bad << ", good K/D: " << Good << "\n";

    // ------------------------------------------------------------------
    // 3. dynamic_cast: "is this Ability really a Fireball?"
    // ------------------------------------------------------------------
    std::cout << "3. dynamic_cast\n";

    std::vector<std::unique_ptr<Ability>> Abilities;
    Abilities.push_back(std::make_unique<Fireball>());
    Abilities.push_back(std::make_unique<Dash>());

    for (const std::unique_ptr<Ability>& A : Abilities)
    {
        A->Activate();                                           // virtual: works for any Ability

        // Checked at runtime. Returns nullptr if the object isn't a Fireball
        if (const Fireball* F = dynamic_cast<const Fireball*>(A.get()))
        {
            F->Explode();                                        // Fireball-only function
        }
        else
        {
            std::cout << "  Not a Fireball\n";
        }
    }

    // ------------------------------------------------------------------
    // 4. What to avoid
    // ------------------------------------------------------------------
    // int C = (int)Speed;   // C-style cast: does whatever it takes without telling you. Avoid
    //
    // dynamic_cast with a reference instead of a pointer throws an exception if it fails:
    //   Fireball& F = dynamic_cast<Fireball&>(*A);   // prefer the pointer version
}
