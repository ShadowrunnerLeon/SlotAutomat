#include "StartState.h"
#include "../../RenderHelper/RenderHelper.h"

StartState::StartState() {}
void StartState::Activate()
{
    sf::Vector2i mousePosition;
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(window);
            auto translatedMousePosition = window.mapPixelToCoords(mousePosition);
            if (startButton.first.getGlobalBounds().contains(translatedMousePosition))
            {
                deactivateFlag = true;
                break;
            }
        }
    }
}

bool StartState::SetDeactivateStatus() { deactivateFlag = false; }
bool StartState::GetDeactivateStatus() { return deactivateFlag; }