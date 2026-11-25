#pragma once

// Ability cooldown without Tick: the caller passes the current time on every call.
class Cooldown
{
public:

    explicit Cooldown(float InDuration);

    // Can the ability be used at this time?
    bool IsReady(float CurrentTime) const;

    // Use the ability now. Does nothing if it is still on cooldown.
    bool TryUse(float CurrentTime);

    // Seconds left until the ability is ready. Never negative.
    float GetTimeRemaining(float CurrentTime) const;

private:

    // How long the cooldown lasts, in seconds
    float Duration = 0.0f;

    // Time at which the ability is ready again. 0 means ready from the start.
    float ReadyTime = 0.0f;
};
