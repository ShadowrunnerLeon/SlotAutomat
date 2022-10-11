#ifndef _SPINSTATE_H_
#define _SPINSTATE_H_

#include "../State/State.h"

class SpinState : public State
{
    private:
        sf::Time elapsedTime;
        sf::Time timer;
        float spinSpeed;

    public:
        SpinState(sf::Time _timer, float _spinSpeed);
        void Update() override;
};

#endif