
#include <iostream>

#include "Vector.h"

int main()
{
    Vec2 velocity = GetZeroVector();
    Vec2 position = GetZeroVector();
    float deltaTime = 0.1f;

    for (int frame = 1; frame <= 10; frame++)
    {
        Vec2 input = GetZeroVector();
        
        if (frame <= 5)
        {
            input = {1.0f, -1.0f};
        }
        
        velocity = UpdateVelocity2D(velocity, input, deltaTime);
        
        position += velocity * deltaTime;
        
        std::cout << "Frame " << frame
          << " | Velocity: " << velocity.x << ", " << velocity.y
          << " | Length: " << Length(velocity)
          << "\n";
    }

    return 0;
}
