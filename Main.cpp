#include <iostream>
#include <memory>
#include "Vector.h"
#include "DashCharges.h"

struct Player
{
    int Health = 100;
};

struct Enemy
{
    std::weak_ptr<Player> Target;
    
    void Attack()
    {
       if (std::shared_ptr<Player> Locked = Target.lock())
       {
           Locked->Health -= 10;
           std::cout << "Target health: " << Locked->Health << "\n";
       }
       else
       {
           std::cout << "Enemy has no target\n";
       }
    }
};

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

void TestDashCharges()
{
    const int MaxDashCharges = 2;
    const float DashFullRefillDelay = 3.0f;

    DashCharges Dash(MaxDashCharges, DashFullRefillDelay);

    std::cout << std::boolalpha;
    std::cout << "1.  GetCharges(0)   = " << Dash.GetCharges(0.0f) << "    (expected 2)\n";
    std::cout << "2.  TryUse(1)       = " << Dash.TryUse(1.0f) << " (expected true)\n";
    std::cout << "3.  TryUse(2)       = " << Dash.TryUse(2.0f) << " (expected true)\n";
    std::cout << "4.  TryUse(3)       = " << Dash.TryUse(3.0f) << " (expected false)\n";
    std::cout << "5.  GetCharges(4)   = " << Dash.GetCharges(4.0f) << "    (expected 0)\n";
    std::cout << "6.  GetCharges(5)   = " << Dash.GetCharges(5.0f) << "    (expected 2)\n";
    std::cout << "7.  TryUse(5.5)     = " << Dash.TryUse(5.5f) << " (expected true)\n";
    std::cout << "8.  TryUse(6)       = " << Dash.TryUse(6.0f) << " (expected true)\n";
    std::cout << "9.  GetCharges(8.9) = " << Dash.GetCharges(8.9f) << "    (expected 0)\n";
    std::cout << "10. GetCharges(9)   = " << Dash.GetCharges(9.0f) << "    (expected 2)\n";
}

int main()
{
    TestDashCharges();

    std::shared_ptr<Player> PlayerCharacter = std::make_shared<Player>();
    
    Enemy Grunt;
    Grunt.Target = PlayerCharacter;
    
    Grunt.Attack();
    PlayerCharacter.reset();
    Grunt.Attack();
    
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
