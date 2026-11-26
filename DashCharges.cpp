#include "DashCharges.h"

DashCharges::DashCharges(int InMaxCharges)
    : MaxCharges(InMaxCharges)
    , Charges(InMaxCharges)
{
}

bool DashCharges::TryUse()
{
    if (Charges <= 0) return false;
    
    --Charges;
    return true;
}

void DashCharges::Refill()
{
    Charges = MaxCharges;
}
