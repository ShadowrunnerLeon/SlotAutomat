#include "StartState.h"

StartState::StartState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void StartState::Activate()
{
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

void StartState::SetDeactivateStatus() { deactivateFlag = false; }
bool StartState::GetDeactivateStatus() const { return deactivateFlag; }