#pragma once
#include <string>

class Player
{
public:
    
    explicit Player(const std::string& name);
    
    virtual ~Player();
    
    const std::string& GetName() const { return Name; }
    
private:
    
    std::string Name;
};
