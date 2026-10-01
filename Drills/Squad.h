#pragma once
#include <memory>
#include <string>
#include <vector>

class Soldier;

class Squad
{
public:

    // Micro-drills: write your methods here
    
    void AddMember(std::unique_ptr<Soldier> member);
    
    Soldier* GetMember(size_t index) const;
    
    int CountAlive() const;
    
    const Soldier* FindByName(const std::string& name) const;

private:
    
    std::vector<std::unique_ptr<Soldier>> Members;
};
