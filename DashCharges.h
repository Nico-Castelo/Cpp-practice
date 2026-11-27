#pragma once

class DashCharges
{
public:
    
    // Constructor with Max Number of charges we can have
    // MaxCharges is set when it is created and charges are set based on max charges
    explicit DashCharges(int InMaxCharges, float InFullRefillDelay);
    
    // If there are enough charges we use one and return true if not do anything and return false
    bool TryUse(float CurrentTime);
    
    // GetCharges return Charges
    int GetCharges(float CurrentTime);
    
    // Refill sets charges to maxCharges
    void Refill();
    
    void RefillIfReady(float CurrentTime);
    
private:
    
    // Max Charges
    int MaxCharges;
    
    // Number of charges we have 
    int Charges;
    
    float LastUseTime = 0.0f;
    
    float FullRefillDelay;
};
