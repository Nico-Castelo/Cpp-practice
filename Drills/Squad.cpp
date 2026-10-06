#include "Squad.h"

#include <algorithm>
#include <numeric>

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

float Squad::TotalDamage() const
{
    auto TotalDamage = std::accumulate(Members.begin(), Members.end(), 0.0f,
        [](float sum, const std::unique_ptr<Soldier>& member)
        {
            return sum + member->GetDamage();
        });
    
    return TotalDamage;
}

void Squad::RecordKill(const std::string& name)
{
    Kills[name]++;
}

int Squad::GetKills(const std::string& name) const
{
    auto FoundIterator = Kills.find(name);
    if (FoundIterator != Kills.end())
    {
        return FoundIterator->second;
    }
    
    return 0;
}

int Squad::CountByRank(ERank rank) const
{
    auto RankedSoldiers = std::count_if(Members.begin(), Members.end(),
        [rank](const std::unique_ptr<Soldier>& member)
        {
            return member->GetRank() == rank;
        });
    
    return static_cast<int>(RankedSoldiers);
}
