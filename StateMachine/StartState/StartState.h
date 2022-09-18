#ifndef _STARTSTATE_H_
#define _STARTSTATE_H_

#include "../IState/IState.h"

class StartState : public IState
{
    private:
        bool deactivateFlag = false;

    public:
        StartState();
        void Activate() override;
        bool SetDeactivateStatus() override;
        bool GetDeactivateStatus() override;
};

#endif