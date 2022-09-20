#ifndef _STOPSTATE_H_
#define _STOPSTATE_H_

#include "../IState/IState.h"
#include "../../RenderHelper/RenderHelper.h"

class StopState : public IState
{
    private:
        bool deactivateFlag = false;
        RenderHelper& renderHelper;
        int texturesMatchNumber[5];

    public:
        StopState(RenderHelper& _renderHelper);
        void Activate() override;
        void SetDeactivateStatus() override;
        bool GetDeactivateStatus() override;
};

#endif