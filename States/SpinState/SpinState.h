#ifndef _SPINSTATE_H_
#define _SPINSTATE_H_

#include "../IState/IState.h"
#include "../../RenderHelper/RenderHelper.h"

class SpinState : public IState
{
    private:
        bool deactivateFlag = false;
        RenderHelper& renderHelper;
        sf::Time elapsedTime;
        sf::Time timer;
        float spinSpeed;

    public:
        SpinState(RenderHelper& _renderHelper, sf::Time _timer, float _spinSpeed);
        void Activate() override;
        void SetDeactivateStatus() override;
        bool GetDeactivateStatus() const override; 
};

#endif