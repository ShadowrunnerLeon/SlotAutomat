#ifndef _ISTATE_H_
#define _ISTATE_H_

class IState 
{
    public:
        virtual void Activate() = 0;
        virtual void SetDeactivateStatus() = 0;
        virtual bool GetDeactivateStatus() const = 0;
};

#endif