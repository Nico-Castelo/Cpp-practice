#include "Vector.h"
#include <cmath>
#include <algorithm>

// ---------- Vec2: operadores ----------

Vec2 Vec2::operator+(Vec2 other) const
{
    return {x + other.x, y + other.y};
}

Vec2 Vec2::operator-(Vec2 other) const
{
    return {x - other.x, y - other.y};
}

Vec2 Vec2::operator*(float s) const
{
    return {x * s, y * s};
}

Vec2 Vec2::operator/(float s) const
{
    return {x / s, y / s};
}

Vec2& Vec2::operator+=(Vec2 other)
{
    x += other.x;
    y += other.y;
    return *this;
}

// ---------- Vec2: métodos ----------

float Vec2::LengthSquared() const
{
    return (x * x) + (y * y);
}

float Vec2::Length() const
{
    return std::sqrt(LengthSquared());
}

Vec2 Vec2::Normalize() const
{
    float length = Length();

    if (length == 0.0f)
    {
        return Zero();
    }

    // Una división y dos multiplicaciones en vez de dos divisiones
    float invLength = 1.0f / length;

    return *this * invLength;
}

Vec2 Vec2::ClampLength(float maxLength) const
{
    float lengthSquared = LengthSquared();

    if (lengthSquared <= maxLength * maxLength) return *this;

    float length = std::sqrt(lengthSquared);

    float scale = maxLength / length;

    return *this * scale;
}

Vec2 Vec2::Zero()
{
    return {0.0f, 0.0f};
}

float Vec2::Dist(Vec2 a, Vec2 b)
{
    return (b - a).Length();
}

// Distancia al cuadrado: sin raíz, para comparar con un radio al cuadrado
float Vec2::DistSquared(Vec2 a, Vec2 b)
{
    return (b - a).LengthSquared();
}

// ---------- Vector: gameplay/movimiento ----------

bool Vector::IsOnSight(Vec2 enemyPos, Vec2 playerPos, float detectionRadius)
{
    return Vec2::DistSquared(enemyPos, playerPos) < detectionRadius * detectionRadius;
}

Vec2 Vector::MoveTowards(Vec2 current, Vec2 target, float speed, float deltaTime)
{
    float maxStepPerFrame = speed * deltaTime;

    Vec2 vector = target - current;

    float distance = vector.Length();

    // Si este frame llegaríamos o nos pasaríamos, nos quedamos justo en el target
    if (distance <= maxStepPerFrame) return target;

    // Dividir por la distancia ya calculada normaliza sin una segunda raíz
    float scale = maxStepPerFrame / distance;

    return current + vector * scale;
}

float Vector::ApplyFriction(float velocity, float friction, float deltaTime)
{
    float frictionStep = friction * deltaTime;

    if (std::abs(velocity) <= frictionStep) return 0.0f;

    if (velocity > 0.0f) return velocity - frictionStep;

    return velocity + frictionStep;
}

float Vector::Accelerate(float velocity, float direction, float acceleration, float maxSpeed, float deltaTime)
{
    velocity += direction * acceleration * deltaTime;

    return std::clamp(velocity, -maxSpeed, maxSpeed);
}

float Vector::UpdateVelocity(float velocity, float direction, float deltaTime)
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

Vec2 Vector::Accelerate2D(Vec2 velocity, Vec2 input, float acceleration, float maxSpeed, float deltaTime)
{
    Vec2 clampedInput = input.ClampLength(1.0f);

    velocity += clampedInput * acceleration * deltaTime;

    return velocity.ClampLength(maxSpeed);
}

Vec2 Vector::ApplyFriction2D(Vec2 velocity, float friction, float deltaTime)
{
    return MoveTowards(velocity, Vec2::Zero(), friction, deltaTime);
}

Vec2 Vector::UpdateVelocity2D(Vec2 velocity, Vec2 input, float deltaTime)
{
    float acceleration = 600.0f;
    float friction = 900.0f;
    float maxSpeed = 300.0f;

    // Equivalente 2D de "direction != 0": hay input si su longitud no es cero
    if (input.LengthSquared() > 0.0f)
    {
        return Accelerate2D(velocity, input, acceleration, maxSpeed, deltaTime);
    }

    return ApplyFriction2D(velocity, friction, deltaTime);
}
