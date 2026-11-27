#include <iostream>

#include "Vector.h"

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
        
        if (bJumpPressed && IsOnGround(PositionY, GroundY))
        {
            VelocityY = -JumpSpeed;
        }
        
        VelocityY += Gravity * DeltaTime;
            
        PositionY += VelocityY * DeltaTime;
        
        ClampToGround(PositionY, VelocityY, GroundY);
            
        std::cout << "Frame: " << i << " "<< PositionY << " and " << VelocityY << "\n";
    }
    
    return 0;
}
