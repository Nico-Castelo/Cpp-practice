#pragma once
#include <string>

enum class ERank
{
    Recruit,
    Veteran,
    Captain,
};

class Soldier
{
public:

    explicit Soldier(const std::string& name, float health = 100.0f)
        : Name(name)
        , Health(health)
    {
    }

    virtual ~Soldier() = default;

    const std::string& GetName() const { return Name; }

    float GetHealth() const { return Health; }
    
    std::string GetRankName() const;
    
    ERank GetRank() const { return Rank; }
    
    void Promote();

    bool IsAlive() const { return Health > 0.0f; }

    void TakeDamage(float amount) { Health = (Health - amount > 0.0f) ? Health - amount : 0.0f; }
    
    virtual float GetDamage() const { return 10.0f; }

private:

    std::string Name;

    float Health = 100.0f;
    
    ERank Rank = ERank::Recruit;
};
