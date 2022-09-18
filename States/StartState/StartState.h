#ifndef _STARTSTATE_H_
#define _STARTSTATE_H_

#include "../IState/IState.h"
#include "../../RenderHelper/RenderHelper.h"

class StartState : public IState
{
    private:
        bool deactivateFlag = false;
        RenderHelper renderHelper;

    public:
        StartState(RenderHelper& _renderHelper);
        void Activate() override;
        void SetDeactivateStatus() override;
        bool GetDeactivateStatus() override;
};

#endif