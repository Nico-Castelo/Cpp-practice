#include "Soldier.h"

std::string Soldier::GetRankName() const
{
    switch (Rank)
    {
    case ERank::Recruit:
        return "Recruit";
    case ERank::Veteran:
        return "Veteran";
    case ERank::Captain:
        return "Captain";
        
    default:
        return "Unknown";
    }
}

void Soldier::Promote()
{
    if (Rank == ERank::Recruit)
    {
        Rank = ERank::Veteran;
    } 
    else if (Rank == ERank::Veteran)
    {
        Rank = ERank::Captain;
    }   
}
