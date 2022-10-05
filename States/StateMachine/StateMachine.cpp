#include "StateMachine.h"
#include <SFML/Graphics.hpp>

StateMachine::StateMachine() {}
void StateMachine::AddState(IState* state) { states.push_back(state); }
void StateMachine::Loop()
{
    if (states[index]->IsFinished())
    {
        states[index]->SetFinishStatus();

        if (index + 1 > states.size() - 1) index = -1;
        states[++index]->Update();
    }
    else
    {
        states[index]->Update();
    }
}