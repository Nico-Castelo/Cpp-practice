#include "Squad.h"

#include <algorithm>

#include "Soldier.h"

// Micro-drills: write your definitions here
void Squad::AddMember(std::unique_ptr<Soldier> member)
{
    Members.push_back(std::move(member));
}

Soldier* Squad::GetMember(size_t index) const
{
    if (index >= Members.size())
    {
        return nullptr;
    }
    return Members[index].get();
}

int Squad::CountAlive() const
{
    auto AliveCount = std::count_if(Members.begin(), Members.end(),
        [](const std::unique_ptr<Soldier>& member)
        {
            return member->IsAlive();
        });
    
    return static_cast<int>(AliveCount);
}

const Soldier* Squad::FindByName(const std::string& name) const
{
    auto FoundIterator = std::find_if(Members.begin(), Members.end(),
        [&name](const std::unique_ptr<Soldier>& member)
        {
            return member->GetName() == name;
        });
    
    if (FoundIterator != Members.end())
    {
        return FoundIterator->get();
    }
    
    return nullptr;
}
