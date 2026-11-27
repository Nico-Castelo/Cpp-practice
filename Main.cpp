#include <iostream>

#include "Vector.h"

float ApplyGravity(float Velocity, float Gravity, float DeltaTime)
{
    return Velocity + Gravity * DeltaTime;
}

bool CanJump(bool bJumpPressed, float PositionY, float GroundY)
{
    return bJumpPressed && IsOnGround(PositionY, GroundY);
}

bool TryJump(float& Velocity, bool bJumpPressed, float PositionY, float GroundY, float JumpSpeed)
{
    if (!CanJump(bJumpPressed, PositionY, GroundY)) return false;

    Velocity = -JumpSpeed;
    return true;
}

float Move(float PositionY, float VelocityY, float DeltaTime)
{
    return PositionY + VelocityY * DeltaTime;
}

void PrintFrame(float PositionY, float VelocityY, int Frame)
{
    std::cout << "Frame: " << Frame << " " << PositionY << " and " << VelocityY << "\n";
}

int main()
{
    float PositionY = 0.0f;
    float VelocityY = 0.0f;
    
    float Gravity = 1000.0f;
    float JumpSpeed = 500.0f;
    float GroundY = 0.0f;
    float DeltaTime = 0.1f;
    
    bool bJumpPressed = false;

    for (int i = 1; i <= 15; ++i)
    {
        bJumpPressed = (i == 1);
        
        TryJump(VelocityY, bJumpPressed, PositionY, GroundY, JumpSpeed);
        
        VelocityY = ApplyGravity(VelocityY, Gravity, DeltaTime);
            
        PositionY = Move(PositionY, VelocityY, DeltaTime);
        
        ClampToGround(PositionY, VelocityY, GroundY);
            
        PrintFrame(PositionY, VelocityY, i);
    }
    
    return 0;
}
