#ifndef _SPINSTATE_H_
#define _SPINSTATE_H_

#include "../IState/IState.h"
#include "../../RenderHelper/RenderHelper.h"

class SpinState : public IState
{
    private:
        bool deactivateFlag = false;
        RenderHelper renderHelper;

    public:
        SpinState(RenderHelper& _renderHelper);
        void Activate() override;
        void SetDeactivateStatus() override;
        bool GetDeactivateStatus() override; 
};

#endif