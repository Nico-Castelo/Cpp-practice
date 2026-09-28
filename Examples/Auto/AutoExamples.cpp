#include "AutoExamples.h"

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

void RunAutoExamples()
{
    // ------------------------------------------------------------------
    // 1. auto deduces the type at COMPILE time from what you assign.
    //    The variable still has a fixed type: you just don't write it.
    // ------------------------------------------------------------------
    std::cout << "1. What auto deduces\n";

    auto A = 5;                      // int
    auto B = 5.0f;                   // float
    auto C = 5.0;                    // double (careful: no 'f')
    auto S = std::string("Wolf");    // std::string
    auto Name = "Wolf";              // const char*, NOT std::string

    std::cout << "  " << A << ", " << B << ", " << C << ", " << S << ", " << Name << "\n";

    // A = "text";                   // ERROR: A is an int forever

    // ------------------------------------------------------------------
    // 2. Where auto helps: long type names
    // ------------------------------------------------------------------
    std::cout << "2. Long types\n";

    std::unordered_map<std::string, int> Ammo = { { "Arrows", 20 }, { "Bombs", 3 } };

    // Without auto: std::unordered_map<std::string, int>::iterator It = ...
    auto It = Ammo.find("Arrows");
    if (It != Ammo.end())
    {
        std::cout << "  " << It->first << ": " << It->second << "\n";
    }

    auto Katana = std::make_unique<std::string>("Katana");   // std::unique_ptr<std::string>
    std::cout << "  " << *Katana << "\n";

    // ------------------------------------------------------------------
    // 3. Trap: auto drops const and &. Add them yourself
    // ------------------------------------------------------------------
    std::cout << "3. Copy vs reference\n";

    std::vector<std::string> Names = { "Wolf", "Genichiro" };

    auto Copy = Names[0];            // COPY: changing it doesn't touch the vector
    auto& Ref = Names[0];            // reference: changes the original
    const auto& ReadOnly = Names[1]; // reference, read only, no copy

    Copy += " (copy)";
    Ref += " (changed)";

    std::cout << "  Copy: " << Copy << "\n";
    std::cout << "  Names[0]: " << Names[0] << "\n";
    std::cout << "  ReadOnly: " << ReadOnly << "\n";

    // ------------------------------------------------------------------
    // 4. auto in range-for: same rule
    // ------------------------------------------------------------------
    std::cout << "4. Range-for\n";

    for (const auto& N : Names)      // no copies, read only
    {
        std::cout << "  " << N << "\n";
    }

    // ------------------------------------------------------------------
    // 5. When NOT to use auto: when the type isn't obvious to the reader
    // ------------------------------------------------------------------
    //   auto Value = ComputeSomething();   // int? float? a pointer? Write the type instead
}
