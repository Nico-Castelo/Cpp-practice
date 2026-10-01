#pragma once

enum class EDamageType
{
    Physical,
    Fire,
};

struct HitInfo
{
    float Damage = 25.0f;
    
    EDamageType Type = EDamageType::Physical;
    
    bool bIsCrtical = false;
};
