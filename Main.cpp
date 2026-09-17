
#include <iostream>

#include "Item.h"

int main()
{
    const Item potion(1, 0.5);
    
    std::cout << "Id: " << potion.GetId() << "\n";
    std::cout << "Weight: " << potion.GetWeight() << "\n";
    
    return 0;
}
