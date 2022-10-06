#ifndef _STARTSTATE_H_
#define _STARTSTATE_H_

#include "../State/State.h"

class StartState : public State
{
    public:
        StartState(RenderHelper& _renderHelper);
        inline void CheckStartButtonPressed();
        void Update() override;
};

#endif