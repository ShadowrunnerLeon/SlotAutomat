#ifndef _STOPSTATE_H_
#define _STOPSTATE_H_

#include "../State/State.h"

class StopState : public State
{
    public:
        StopState(RenderHelper& _renderHelper);
        inline void IsStopButtonPressed() const;
        inline bool SlotsInBounds(int range) const;
        inline void CalculateScore(int range);
        inline void FindSlotsInBounds();
        void Update() override;
};

#endif