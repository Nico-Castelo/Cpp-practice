#pragma once

class Item
{
public:
    
    Item(int id, float weight);
    
    int Getid() const;
    
    float GetWeight() const;
    
private:
    
    int Id;
    
    float Weight;
    
};
