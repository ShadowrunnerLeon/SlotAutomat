#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

#include "../IState/IState.h"
#include <vector>

class StateMachine
{
    private:
        std::vector<IState*> states;
        int index = 0;
        
    public:
        StateMachine();
        void AddState(IState* state);
        void Loop();
};

#endif