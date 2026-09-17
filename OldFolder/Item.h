#pragma once

class Item
{
public:
    
    Item(int id, float weight);
    
    virtual ~Item();
    
    int GetId() const;
    
    float GetWeight() const;
    
private:
    
    int Id;
    
    float Weight;
};
