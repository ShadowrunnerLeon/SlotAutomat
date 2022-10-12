#include "StateMachine.h"
#include <SFML/Graphics.hpp>

StateMachine::StateMachine() {}
void StateMachine::AddState(State* state) { states.push_back(state); }
void StateMachine::Update()
{
    if (states[index]->IsFinished())
    {
        states[index]->SetFinishStatus(false);

        if (index + 1 > states.size() - 1) index = -1;
        states[++index]->Update();
    }
    else
    {
        states[index]->Update();
    }
}