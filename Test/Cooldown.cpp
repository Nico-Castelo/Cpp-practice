#include "Cooldown.h"

Cooldown::Cooldown(float InDuration)
    : Duration(InDuration)
{
}

bool Cooldown::TryUse(float Time)
{
    if (CooldownUntil - Time >= cooldown)
    {
        return true;
    }
    
    return false;
}
