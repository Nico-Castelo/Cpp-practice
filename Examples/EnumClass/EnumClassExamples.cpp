#include "EnumClassExamples.h"

#include <cstdint>    // uint8_t
#include <iostream>

namespace EnumClassExample
{
    // 1. Basic enum class: a fixed set of named values (typical for states)
    enum class EState
    {
        Idle,        // 0
        Attacking,   // 1
        Blocking,    // 2
        Dead         // 3
    };

    // 2. Choosing the underlying type (default is int). uint8_t = 1 byte
    enum class EDamageType : uint8_t
    {
        Physical,
        Fire,
        Poison
    };

    // 3. Converting to text with a switch (very common for logs and UI)
    const char* ToString(EState state)
    {
        switch (state)
        {
            case EState::Idle:      return "Idle";
            case EState::Attacking: return "Attacking";
            case EState::Blocking:  return "Blocking";
            case EState::Dead:      return "Dead";
        }
        return "Unknown";   // only reached with an invalid value
    }

    // Why not the old plain 'enum'? (don't do this)
    //   enum OldState { Idle, Dead };
    //   int X = Idle;     // compiles: converts to int silently
    //   'Idle' clashes with any other 'Idle' in the same scope
}

using EnumClassExample::EState;
using EnumClassExample::EDamageType;
using EnumClassExample::ToString;

void RunEnumClassExamples()
{
    // ------------------------------------------------------------------
    // 1. Declaring and assigning: always with the prefix EState::
    // ------------------------------------------------------------------
    std::cout << "1. Declare and assign\n";

    EState State = EState::Idle;
    std::cout << "  State: " << ToString(State) << "\n";

    State = EState::Attacking;
    std::cout << "  State: " << ToString(State) << "\n";

    // ------------------------------------------------------------------
    // 2. Comparing
    // ------------------------------------------------------------------
    std::cout << "2. Compare\n";

    if (State == EState::Attacking)
    {
        std::cout << "  Can't block while attacking\n";
    }

    // ------------------------------------------------------------------
    // 3. switch: one branch per state
    // ------------------------------------------------------------------
    std::cout << "3. switch\n";

    switch (State)
    {
        case EState::Idle:
            std::cout << "  Waiting\n";
            break;                          // without break, it falls into the next case
        case EState::Attacking:
            std::cout << "  Swinging the sword\n";
            break;
        default:                            // every other value
            std::cout << "  Something else\n";
            break;
    }

    // ------------------------------------------------------------------
    // 4. Converting to and from int: always explicit with static_cast
    // ------------------------------------------------------------------
    std::cout << "4. Convert\n";

    int AsInt = static_cast<int>(State);           // 1
    std::cout << "  Attacking as int: " << AsInt << "\n";

    EState FromInt = static_cast<EState>(3);       // Dead. Careful: no range check
    std::cout << "  3 as EState: " << ToString(FromInt) << "\n";

    // int Bad = State;                            // ERROR: enum class doesn't convert on its own

    // ------------------------------------------------------------------
    // 5. Custom underlying type
    // ------------------------------------------------------------------
    std::cout << "5. Underlying type\n";

    EDamageType Type = EDamageType::Fire;
    std::cout << "  Size of EDamageType: " << sizeof(EDamageType) << " byte\n";

    // Trap: std::cout prints a uint8_t as a CHARACTER. Cast to int to print the number
    std::cout << "  Fire as number: " << static_cast<int>(Type) << "\n";
}
