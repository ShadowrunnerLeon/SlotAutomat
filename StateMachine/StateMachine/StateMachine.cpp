#include "StateMachine.h"

StateMachine::StateMachine() {}
void StateMachine::AddState(IState* state) { states.push_back(state); }
void StateMachine::StartLoop()
{
    while (1)
    {
        for (auto state : states)
        {
            state->Activate();
            while (!state->IsDeactivated());
        }
    }
}