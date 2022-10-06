#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

#include "../State/State.h"
#include <vector>

class StateMachine
{
    private:
        std::vector<State*> states;
        int index = 0;
        
    public:
        StateMachine();
        void AddState(State* state);
        void Loop();
};

#endif