#pragma once
#include <string>

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

    bool IsAlive() const { return Health > 0.0f; }

    void TakeDamage(float amount) { Health = (Health - amount > 0.0f) ? Health - amount : 0.0f; }

private:

    std::string Name;

    float Health = 100.0f;
};
