#pragma once


enum class GateState
{
    Closed,
    Open,
    Locked
};


class Gate
{
public:
    
    Gate(int InId, GateState InState);
    
    bool IsLocked() const;
    
private:
    
    int Id;
    
    GateState State;
    
};
