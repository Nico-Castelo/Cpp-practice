#pragma once

class Cooldown
{
public:
    
    Cooldown(float InDuration);
    
    bool TryUse(float Time);
    
private:
    
    float Duration = 2.5f;
    
    float cooldown = 5.0f;
    
    float CooldownUntil = 0.0f;
};
