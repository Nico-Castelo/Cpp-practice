#include "Cooldown.h"

#include <algorithm>

Cooldown::Cooldown(float InDuration)
    : Duration(InDuration)
{
}

bool Cooldown::IsReady(float CurrentTime) const
{
    return CurrentTime >= ReadyTime;
}

bool Cooldown::TryUse(float CurrentTime)
{
    if (IsReady(CurrentTime))
    {
        ReadyTime = CurrentTime + Duration;
        return true;
    }
    
    return false;
}

float Cooldown::GetTimeRemaining(float CurrentTime) const
{
    return std::max(0.0f, ReadyTime - CurrentTime);
}
