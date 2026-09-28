#include "Inventory.h"

#include <algorithm>   // std::copy
#include <iostream>

Inventory::Inventory(size_t size)
    : Size(size)
    , Slots(new int[size]{})          // {} = all values set to 0
{
    std::cout << "regular constructor\n";
}

Inventory::~Inventory()
{
    std::cout << "destructor\n";
    delete[] Slots;                   // new[] is freed with delete[]
}

Inventory::Inventory(const Inventory& other)
    : Size(other.Size)                // 1. same size as the original
    , Slots(new int[other.Size])      // 2. MY OWN new array on the heap
{
    // 3. copy the values: from, to (one past the last), destination
    std::copy(other.Slots, other.Slots + other.Size, Slots);

    std::cout << "copy constructor\n";
}

void Inventory::SetSlot(size_t index, int value)
{
    if (index < Size)
    {
        Slots[index] = value;
    }
}

void Inventory::Print(const char* label) const
{
    std::cout << label << " (array at " << Slots << "): ";

    for (size_t i = 0; i < Size; ++i)
    {
        std::cout << "[" << Slots[i] << "]";
    }

    std::cout << "\n";
}
