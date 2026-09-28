#include "OverloadingExamples.h"

#include <iostream>
#include <string>

namespace OverloadingExample
{
    // 1. Same name, different parameter TYPES
    void Print(int value)                { std::cout << "  int: " << value << "\n"; }
    void Print(float value)              { std::cout << "  float: " << value << "\n"; }
    void Print(const std::string& value) { std::cout << "  string: " << value << "\n"; }

    // 2. Same name, different NUMBER of parameters
    float ApplyDamage(float health, float damage)
    {
        return health - damage;
    }

    float ApplyDamage(float health, float damage, float multiplier)
    {
        return health - damage * multiplier;
    }

    // 3. A default parameter can replace an overload
    float Heal(float health, float amount = 25.0f)   // the default goes in the declaration
    {
        return health + amount;
    }

    // 4. Overloaded methods inside a class
    class Inventory
    {
    public:
        void AddItem(int id)                  { std::cout << "  Added item by id: " << id << "\n"; }
        void AddItem(const std::string& name) { std::cout << "  Added item by name: " << name << "\n"; }
    };

    // Doesn't compile: two versions that differ ONLY in the return type
    //   int   GetValue();
    //   float GetValue();   // ERROR
}

using namespace OverloadingExample;

void RunOverloadingExamples()
{
    // ------------------------------------------------------------------
    // 1. The compiler picks the version that matches the argument
    // ------------------------------------------------------------------
    std::cout << "1. By type\n";

    Print(5);                       // int
    Print(5.0f);                    // float
    Print(std::string("Wolf"));     // string
    Print("Genichiro");             // const char* -> converted to std::string

    // Print(5.0);                  // ERROR: 5.0 is a double. int or float? Ambiguous

    // ------------------------------------------------------------------
    // 2. By number of parameters
    // ------------------------------------------------------------------
    std::cout << "2. By number of parameters\n";

    std::cout << "  Normal hit: " << ApplyDamage(100.0f, 20.0f) << "\n";          // 80
    std::cout << "  Critical hit: " << ApplyDamage(100.0f, 20.0f, 2.0f) << "\n";  // 60

    // ------------------------------------------------------------------
    // 3. Default parameter
    // ------------------------------------------------------------------
    std::cout << "3. Default parameter\n";

    std::cout << "  Heal default: " << Heal(50.0f) << "\n";          // 75
    std::cout << "  Heal custom: " << Heal(50.0f, 10.0f) << "\n";    // 60

    // ------------------------------------------------------------------
    // 4. Overloaded methods
    // ------------------------------------------------------------------
    std::cout << "4. Methods\n";

    Inventory Bag;
    Bag.AddItem(42);
    Bag.AddItem("Healing Gourd");
}
