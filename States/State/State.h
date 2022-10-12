#ifndef _STATE_H_
#define _STATE_H_

#include "../../RenderHelper/RenderHelper.h"

class State 
{
    public:
        bool finishStatus;
        RenderHelper *renderHelper;

        State() = default;
        virtual void Update() = 0;
};

#endif