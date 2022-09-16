#ifndef _ISTATE_H_
#define _ISTATE_H_

class IState 
{
    public:
        virtual void Activate() = 0;
        virtual void Deactivate() = 0;
};

#endif