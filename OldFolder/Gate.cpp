#include "Gate.h"

Gate::Gate(int InId, GateState InState)
    : Id(InId)
    , State(InState)
{
}

bool Gate::IsLocked() const
{
    return State == GateState::Locked;
}
