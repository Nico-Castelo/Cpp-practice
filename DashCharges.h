#pragma once

class DashCharges
{
public:
    
    // Constructor with Max Number of charges we can have
    // MaxCharges is set when it is created and charges are set based on max charges
    explicit DashCharges(int InMaxCharges);
    
    // If there are enough charges we use one and return true if not do anything and return false
    bool TryUse();
    
    // GetCharges return Charges
    int GetCharges() const { return Charges; }
    
    // Refill sets charges to maxCharges
    void Refill();
    
private:
    
    // Max Charges
    int MaxCharges;
    
    // Number of charges we have 
    int Charges;
};
