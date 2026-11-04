#include "Vector.h"
#include <cmath>
#include <algorithm>

Vec2 GetVector(Vec2 a, Vec2 b)
{
    return {b.x - a.x, b.y - a.y};
}

float LengthSquared(Vec2 a)
{
    return (a.x * a.x) + (a.y * a.y);
}

float Length(Vec2 a)
{
    float sum = LengthSquared(a);

    return std::sqrt(sum);
}

float Dist(Vec2 a, Vec2 b)
{
    return Length({b.x - a.x, b.y - a.y});
}

// Distancia al cuadrado: sin raíz, para comparar con un radio al cuadrado
float DistSquared(Vec2 a, Vec2 b)
{
    Vec2 vector = {b.x - a.x, b.y - a.y};

    return LengthSquared(vector);
}

Vec2 Normalize(Vec2 a)
{
    float length = Length(a);

    if (length == 0.0f)
    {
        return {0.0f,0.0f};
    }

    // Una división y dos multiplicaciones en vez de dos divisiones
    float invLength = 1.0f / length;

    return {a.x * invLength, a.y * invLength};
}

bool IsOnSight(Vec2 enemyPos, Vec2 playerPos, float detectionRadius)
{
    return DistSquared(enemyPos, playerPos) < detectionRadius * detectionRadius;
}

Vec2 MoveTowards(Vec2 current, Vec2 target, float speed, float deltaTime)
{
    float maxStepPerFrame = speed * deltaTime;
    
    Vec2 vector = GetVector(current, target);

    float distance = Length(vector);

    // Si este frame llegaríamos o nos pasaríamos, nos quedamos justo en el target
    if (distance <= maxStepPerFrame) return target;

    // Dividir por la distancia ya calculada normaliza sin una segunda raíz
    float scale = maxStepPerFrame / distance;

    return {current.x + vector.x * scale, current.y + vector.y * scale};
}

float ApplyFriction(float velocity, float friction, float deltaTime)
{
    float frictionStep = friction * deltaTime;

    if (std::abs(velocity) <= frictionStep) return 0.0f;

    if (velocity > 0.0f) return velocity - frictionStep;

    return velocity + frictionStep;
}

float Accelerate(float velocity, float direction, float acceleration, float maxSpeed, float deltaTime)
{
    velocity += direction * acceleration * deltaTime;

    return std::clamp(velocity, -maxSpeed, maxSpeed);
}

float UpdateVelocity(float velocity, float direction, float deltaTime)
{
    float acceleration = 600.0f;
    float friction = 900.0f;
    float maxSpeed = 300.0f;
    
    if (direction != 0.0f)
    {
        return Accelerate(velocity, direction, acceleration, maxSpeed, deltaTime);
    }
    
    return ApplyFriction(velocity, friction, deltaTime);
}

Vec2 ClampLength(Vec2 v, float maxLength)
{
    float length = Length(v);
    
    if (length <= maxLength) return v;
    
    Vec2 direction = Normalize(v);
    
    return {direction.x * maxLength, direction.y * maxLength};
}
