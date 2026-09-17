#pragma once

class Ability
{
public:
    
    Ability();
    
    virtual ~Ability();
    
    virtual void Execute() const;
};
