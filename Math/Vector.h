#pragma once

// Vector 2D al estilo FVector de Unreal:
// - Los datos (x, y) y lo que es "del vector" van como miembros: v.Length(), v + w...
// - Lo que opera sobre dos vectores sin dueño claro va como static: Vec2::Dist(a, b)
struct Vec2
{
    float x = 0.0f;
    float y = 0.0f;

    // Operadores como miembros: el operando izquierdo es *this
    Vec2 operator+(Vec2 other) const;
    Vec2 operator-(Vec2 other) const;
    Vec2 operator*(float s) const;
    Vec2 operator/(float s) const;
    Vec2& operator+=(Vec2 other);

    // const: no modifican el vector sobre el que se llaman
    float LengthSquared() const;
    float Length() const;
    Vec2 Normalize() const;
    Vec2 ClampLength(float maxLength) const;

    static Vec2 Zero();
    static float Dist(Vec2 a, Vec2 b);
    static float DistSquared(Vec2 a, Vec2 b);
};

// Funciones de gameplay/movimiento: static, se llaman sin instancia, Vector::UpdateVelocity(...)
class Vector
{
public:
    static bool IsOnSight(Vec2 enemyPos, Vec2 playerPos, float detectionRadius);

    static Vec2 MoveTowards(Vec2 current, Vec2 target, float speed, float deltaTime);

    // 1D
    static float Accelerate(float velocity, float direction, float acceleration, float maxSpeed, float deltaTime);
    static float ApplyFriction(float velocity, float friction, float deltaTime);
    static float UpdateVelocity(float velocity, float direction, float deltaTime);

    // 2D
    static Vec2 Accelerate2D(Vec2 velocity, Vec2 input, float acceleration, float maxSpeed, float deltaTime);
    static Vec2 ApplyFriction2D(Vec2 velocity, float friction, float deltaTime);
    static Vec2 UpdateVelocity2D(Vec2 velocity, Vec2 input, float deltaTime);
};
