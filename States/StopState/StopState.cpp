#include "StopState.h"
#include "../../RenderHelper/RenderHelper.h"

StopState::StopState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void StopState::Activate()
{
    std::cout << "stop" << std::endl;

    for (auto& slot : renderHelper.GetSlots()) 
    {
        renderHelper.GetWindow().draw(slot);
    }

    deactivateFlag = true;
}

void StopState::SetDeactivateStatus() { deactivateFlag = false; }
bool StopState::GetDeactivateStatus() { return deactivateFlag; }