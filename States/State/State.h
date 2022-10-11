#ifndef _STATE_H_
#define _STATE_H_

#include "../../RenderHelper/RenderHelper.h"

class State 
{
    private:
        bool finishStatus;

    public:
        State() = default;
        virtual void Update() = 0;
        void SetFinishStatus(bool status);
        bool IsFinished() const;
};

#endif