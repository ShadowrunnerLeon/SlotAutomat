#include "StopState.h"
#include "../../RenderHelper/RenderHelper.h"

StopState::StopState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void StopState::Activate()
{
    for (auto& slot : renderHelper.GetSlots()) 
    {
        if (slot.getPosition().y >= 200.f) renderHelper.GetWindow().draw(slot);
    }

    sf::Vector2i mousePosition;
    sf::Event event;

    while (renderHelper.GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) renderHelper.GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(renderHelper.GetWindow());
            auto translatedMousePosition = renderHelper.GetWindow().mapPixelToCoords(mousePosition);
            if (renderHelper.GetStartButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                deactivateFlag = true;
                return;
            }
        }
    } 
}

void StopState::SetDeactivateStatus() { deactivateFlag = false; }
bool StopState::GetDeactivateStatus() { return deactivateFlag; }