#ifndef _STATE_H_
#define _STATE_H_

class State 
{
    private:
        bool finishStatus;
        RenderHelper& renderHelper;

    public:
        State(RenderHelper& _renderHelper);
        virtual void Update() = 0;
        void SetFinishStatus(bool status);
        bool IsFinished() const;
        RenderHelper& GetRednderHelper() const;
};

#endif