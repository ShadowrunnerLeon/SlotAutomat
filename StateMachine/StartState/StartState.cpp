#include "StartState.h"

StartState::StartState() {}
void StartState::Activate()
{
    while(!isStart);
    isStart = false;
    deactivateFlag = true;
}

bool StartState::IsDeactivated() { return deactivateFlag; }