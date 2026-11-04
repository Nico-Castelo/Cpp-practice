#include "Stats.h"

Attribute* Stats::GetAttribute(const std::string& name) const
{
    auto FoundIterator = Attributes.find(name);
    if (FoundIterator != Attributes.end())
    {
        return FoundIterator->second;
    }
    
    return nullptr;
}
