#pragma once

struct Vec2
{
    float x;
    float y;
};

float LengthSquared(Vec2 a);
float Length(Vec2 a);
float Dist(Vec2 a, Vec2 b);
float DistSquared(Vec2 a, Vec2 b);
Vec2 Normalize(Vec2 a);
bool IsOnSight(Vec2 enemyPos, Vec2 playerPos, float detectionRadius);
Vec2 MoveTowards(Vec2 current, Vec2 target, float speed, float deltaTime);
float Accelerate(float velocity, float direction, float acceleration, float maxSpeed, float deltaTime);
float ApplyFriction(float velocity, float friction, float deltaTime);
float UpdateVelocity(float velocity, float direction, float deltaTime);
Vec2 ClampLength(Vec2 v, float maxLength);