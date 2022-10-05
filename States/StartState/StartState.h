#ifndef _STARTSTATE_H_
#define _STARTSTATE_H_

#include "../IState/IState.h"
#include "../../RenderHelper/RenderHelper.h"

class StartState : public IState
{
    private:
        bool SetFinishStatusfalse;
        RenderHelper& renderHelper;

    public:
        StartState(RenderHelper& _renderHelper);
        void Update() override;
};

#endif