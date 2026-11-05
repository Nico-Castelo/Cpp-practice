#include <iostream>
#include "Math/Vector.h"

int main()
{
    
    float velocity = 0.0f;    // empieza parado
    float position = 0.0f;    // empieza en el 0
    float deltaTime = 0.1f;   // el mismo en todos los frames, por simplificar

    for (int frame = 1; frame <= 10; frame++)
    {
        float direction = 0.0f;
        if (frame <= 5) direction = 1.0f;
        
        velocity = Vector::UpdateVelocity(velocity, direction, deltaTime);
        position += velocity * deltaTime;
        std::cout << "Frame: " << frame << " Velocity: " << velocity << " Position: " << position << "\n";
    }

    return 0;
}
