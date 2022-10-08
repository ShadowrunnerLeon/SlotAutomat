#ifndef _STOPSTATE_H_
#define _STOPSTATE_H_

#include "../State/State.h"

class StopState : public State
{
    public:
        StopState(RenderHelper& _renderHelper);
        bool IsStopButtonPressed();
        bool SlotsInBounds(int range) const;
        void CalculateScore(int range);
        void FindSlotsInBounds();
        void Update() override;
};

#endif