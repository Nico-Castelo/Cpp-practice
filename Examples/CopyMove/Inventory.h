#pragma once
#include <cstddef>

// Copy and move example: a class that manages a heap array BY HAND.
// In real code you'd use std::vector (rule of 0). This shows what it does under the hood.
class Inventory
{
public:

    // Regular constructor: allocates an array on the heap
    explicit Inventory(size_t size);

    // 1. Destructor: frees the heap array
    ~Inventory();

    // 2. Copy constructor: creates a NEW object by copying another one
    //    Inventory B = A;
    Inventory(const Inventory& other);

    void SetSlot(size_t index, int value);

    void Print(const char* label) const;

private:

    size_t Size = 0;       // declared before Slots -> initialized before it

    int* Slots = nullptr;  // the pointer lives inside the object; the array lives on the heap
};
