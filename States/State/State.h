#ifndef _STATE_H_
#define _STATE_H_

#include "../../RenderHelper/RenderHelper.h"

class State 
{
    protected:
        bool finishStatus;
        RenderHelper *renderHelper;

    public:
        State() = default;
        virtual void Update() = 0;
        bool IsFinished() { return finishStatus; }
        void SetFinishStatus(bool status) { finishStatus = status; }
};

#endif