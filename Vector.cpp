#include "Vector.h"
#include <cmath>
#include <algorithm>

// ---------- Operadores ----------

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

// ---------- Básicas ----------

// La flecha que va de a hasta b (destino - origen)
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
    return std::sqrt(LengthSquared(a));
}

// Deja la flecha midiendo 1, apuntando igual
Vec2 Normalize(Vec2 a)
{
    float length = Length(a);

    if (length == 0.0f) return GetZeroVector();

    // Una división y dos multiplicaciones en vez de dos divisiones
    float invLength = 1.0f / length;

    return a * invLength;
}

// Si la flecha mide más que maxLength, la recorta a maxLength apuntando igual
Vec2 ClampLength(Vec2 v, float maxLength)
{
    float lengthSquared = LengthSquared(v);

    if (lengthSquared <= maxLength * maxLength) return v;

    float length = std::sqrt(lengthSquared);

    // La parte de la flecha que nos quedamos
    float scale = maxLength / length;

    return v * scale;
}

// ---------- Herramientas ----------

float Dist(Vec2 a, Vec2 b)
{
    return Length(GetVector(a, b));
}

// Distancia al cuadrado: sin raíz, para comparar con un radio al cuadrado
float DistSquared(Vec2 a, Vec2 b)
{
    return LengthSquared(GetVector(a, b));
}

// Acerca current a target un paso de speed * deltaTime, sin pasarse
Vec2 MoveTowards(Vec2 current, Vec2 target, float speed, float deltaTime)
{
    float maxStepPerFrame = speed * deltaTime;

    Vec2 vector = GetVector(current, target);

    float distance = Length(vector);

    // Si este frame llegaríamos o nos pasaríamos, nos quedamos justo en el target
    if (distance <= maxStepPerFrame) return target;

    // La parte del camino que recorremos este frame (reaprovecha distance: sin segunda raíz)
    float scale = maxStepPerFrame / distance;

    return current + vector * scale;
}

// ---------- Mecánicas ----------

bool IsOnSight(Vec2 enemyPos, Vec2 playerPos, float detectionRadius)
{
    return DistSquared(enemyPos, playerPos) < detectionRadius * detectionRadius;
}

// 1D

float Accelerate(float velocity, float direction, float acceleration, float maxSpeed, float deltaTime)
{
    velocity += direction * acceleration * deltaTime;

    return std::clamp(velocity, -maxSpeed, maxSpeed);
}

float ApplyFriction(float velocity, float friction, float deltaTime)
{
    float frictionStep = friction * deltaTime;

    if (std::abs(velocity) <= frictionStep) return 0.0f;

    if (velocity > 0.0f) return velocity - frictionStep;

    return velocity + frictionStep;
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

// 2D

Vec2 Accelerate2D(Vec2 velocity, Vec2 input, float acceleration, float maxSpeed, float deltaTime)
{
    Vec2 clampedInput = ClampLength(input, 1.0f);

    velocity += clampedInput * acceleration * deltaTime;

    return ClampLength(velocity, maxSpeed);
}

// La fricción en 2D: acercar la velocidad al cero sin pasarse
Vec2 ApplyFriction2D(Vec2 velocity, float friction, float deltaTime)
{
    return MoveTowards(velocity, GetZeroVector(), friction, deltaTime);
}

Vec2 UpdateVelocity2D(Vec2 velocity, Vec2 input, float deltaTime)
{
    float acceleration = 600.0f;
    float friction = 900.0f;
    float maxSpeed = 300.0f;

    // Equivalente 2D de "direction != 0": hay input si la flecha mide algo
    if (LengthSquared(input) > 0.0f)
    {
        return Accelerate2D(velocity, input, acceleration, maxSpeed, deltaTime);
    }

    return ApplyFriction2D(velocity, friction, deltaTime);
}

float Lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}

Vec2 Lerp2D(Vec2 a, Vec2 b, float t)
{
    return a + (b - a) * t;
}

float InterpTo(float current, float target, float speed, float deltaTime)
{
    float t = speed * deltaTime;
    
    t = std::clamp(t, 0.0f, 1.0f);
    
    return Lerp(current, target, t);
}

Vec2 InterpTo2D(Vec2 current, Vec2 target, float speed, float deltaTime)
{
    float t = speed * deltaTime;
    
    t = std::clamp(t, 0.0f, 1.0f);
    
    return Lerp2D(current, target, t);
}