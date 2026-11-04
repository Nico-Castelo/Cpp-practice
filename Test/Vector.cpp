#include "Vector.h"
#include <cmath>
#include <algorithm>

Vec2 operator+(Vec2 a, Vec2 b)
{
    return {a.x + b.x, a.y + b.y};
}

Vec2 operator-(Vec2 a, Vec2 b)
{
    return {a.x - b.x, a.y - b.y};
}

Vec2 operator*(Vec2 v, float s)
{
    return {v.x * s, v.y * s};
}

Vec2 operator/(Vec2 v, float s)
{
    return {v.x / s, v.y / s};
}

Vec2& operator+=(Vec2& a, Vec2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vec2 GetVector(Vec2 a, Vec2 b)
{
    return b - a;
}

Vec2 GetZeroVector()
{
    return {0.0f, 0.0f};
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
    return Length(GetVector(a,b));
}

// Distancia al cuadrado: sin raíz, para comparar con un radio al cuadrado
float DistSquared(Vec2 a, Vec2 b)
{
    return LengthSquared(GetVector(a,b));
}

Vec2 Normalize(Vec2 a)
{
    float length = Length(a);

    if (length == 0.0f)
    {
        return GetZeroVector();
    }

    // Una división y dos multiplicaciones en vez de dos divisiones
    float invLength = 1.0f / length;

    return a * invLength;
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

    return current + vector * scale;
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
    float lengthSquared = LengthSquared(v);
    
    if (lengthSquared <= maxLength * maxLength) return v;
    
    float length = std::sqrt(lengthSquared);
    
    float scale = maxLength / length;
    
    return v * scale;
}

Vec2 Accelerate2D(Vec2 velocity, Vec2 input, float acceleration, float maxSpeed, float deltaTime)
{
    Vec2 clampedInput = ClampLength(input, 1.0f);
    
    velocity += clampedInput * acceleration * deltaTime;
    
    return ClampLength(velocity, maxSpeed);
}

Vec2 ApplyFriction2D(Vec2 velocity, float friction, float deltaTime)
{
    return MoveTowards(velocity, GetZeroVector(), friction, deltaTime);
}
