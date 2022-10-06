#ifndef _STOPSTATE_H_
#define _STOPSTATE_H_

#include "../State/State.h"

class StopState : public State
{
    public:
        StopState(RenderHelper& _renderHelper);
        inline bool SlotsInBounds(int range) const;
        inline void CalculateScore(int range);
        void Update() override;
};

#endif