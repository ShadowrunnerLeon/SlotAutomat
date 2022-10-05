#ifndef _ISTATE_H_
#define _ISTATE_H_

class IState 
{
    private:
        bool finishStatus;

    public:
        virtual void Update() = 0;
        void SetFinishStatus(bool status);
        bool IsFinished() const;
};

#endif