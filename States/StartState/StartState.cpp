#include "StartState.h"

StartState::StartState(RenderHelper& _renderHelper) : State(_renderHelper) {}

inline void StartState::CheckStartButtonPressed()
{
    mousePosition = sf::Mouse::getPosition(GetRenderHelper().GetWindow());
    auto translatedMousePosition = GetRenderHelper().GetWindow().mapPixelToCoords(mousePosition);
    if (GetRenderHelper().GetStartButton().first.getGlobalBounds().contains(translatedMousePosition))
    {
        SetFinishStatus(true);
        return;
    }
}

void StartState::Update()
{
    sf::Vector2i mousePosition;
    sf::Event event;

    while (GetRenderHelper().GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) GetRenderHelper().GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed) CheckStartButtonPressed();
    }
}