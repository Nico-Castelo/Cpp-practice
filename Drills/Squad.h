#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

enum class ERank;
class Soldier;

class Squad
{
public:

    // Micro-drills: write your methods here
    
    void AddMember(std::unique_ptr<Soldier> member);
    
    Soldier* GetMember(size_t index) const;
    
    int CountAlive() const;
    
    const Soldier* FindByName(const std::string& name) const;
    
    float TotalDamage() const;
    
    void RecordKill(const std::string& name);
    
    int GetKills(const std::string& name) const;
    
    int CountByRank(ERank rank) const;


private:
    
    std::vector<std::unique_ptr<Soldier>> Members;
    
    std::unordered_map<std::string, int> Kills;
};
