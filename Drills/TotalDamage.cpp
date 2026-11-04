#include "TotalDamage.h"

#include <numeric>

float TotalDamage::GetTotalDamage(const std::vector<float>& Damages) const
{
    auto TotalDamage = std::accumulate(Damages.begin(), Damages.end(), 0.0f);
    
    return static_cast<float>(TotalDamage);
}
