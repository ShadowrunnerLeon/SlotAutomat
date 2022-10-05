#ifndef _STOPSTATE_H_
#define _STOPSTATE_H_

#include "../IState/IState.h"
#include "../../RenderHelper/RenderHelper.h"

class StopState : public IState
{
    private:
        bool SetFinishStatusfalse;
        RenderHelper& renderHelper;

    public:
        StopState(RenderHelper& _renderHelper);
        void Update() override;
};

#endif