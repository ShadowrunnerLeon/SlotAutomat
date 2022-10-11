#include "StartState.h"

void StartState::CheckStartButtonPressed()
{
    auto mousePosition = sf::Mouse::getPosition(RenderHelper::GetInstance().GetWindow());
    auto translatedMousePosition = RenderHelper::GetInstance().GetWindow().mapPixelToCoords(mousePosition);
    if (RenderHelper::GetInstance().GetStartButton().first.getGlobalBounds().contains(translatedMousePosition))
    {
        SetFinishStatus(true);
        return;
    }
}

void StartState::Update()
{
    sf::Vector2i mousePosition;
    sf::Event event;

    while (RenderHelper::GetInstance().GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) RenderHelper::GetInstance().GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed) CheckStartButtonPressed();
    }
}