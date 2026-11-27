#include "DashCharges.h"

DashCharges::DashCharges(int InMaxCharges, float InFullRefillDelay)
    : MaxCharges(InMaxCharges)
    , Charges(InMaxCharges)
    , FullRefillDelay(InFullRefillDelay)
{
}

bool DashCharges::TryUse(float CurrentTime)
{
    RefillIfReady(CurrentTime);
    
    if (Charges <= 0) return false;
    
    --Charges;
    LastUseTime = CurrentTime;
    return true;
}

int DashCharges::GetCharges(float CurrentTime)
{
    RefillIfReady(CurrentTime);
    return Charges;
}

void DashCharges::Refill()
{
    Charges = MaxCharges;
}

void DashCharges::RefillIfReady(float CurrentTime)
{
    float RefillTime = LastUseTime + FullRefillDelay;
    
    if (CurrentTime >= RefillTime)
    {
        Refill();
    }
}

