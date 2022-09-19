#include "StopState.h"
#include "../../RenderHelper/RenderHelper.h"

StopState::StopState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void StopState::Activate()
{
    sf::Clock timer;

    for (auto& slot : renderHelper.GetSlots()) 
    {
        renderHelper.GetWindow().draw(slot);
    }

    elapsedTime += timer.restart();
    std::cout << elapsedTime.asSeconds() << std::endl;
    if (elapsedTime >= sf::seconds(2))
    {
        elapsedTime = sf::seconds(0);
        deactivateFlag = true;
    } 
}

void StopState::SetDeactivateStatus() { deactivateFlag = false; }
bool StopState::GetDeactivateStatus() { return deactivateFlag; }