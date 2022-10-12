#include "StartState.h"

StartState::StartState(RenderHelper* _renderHelper)
{
    renderHelper = _renderHelper;
}

void StartState::CheckStartButtonPressed()
{
    auto mousePosition = sf::Mouse::getPosition(renderHelper->GetWindow());
    auto translatedMousePosition = renderHelper->GetWindow().mapPixelToCoords(mousePosition);
    if (renderHelper->GetStartButton().text.getGlobalBounds().contains(translatedMousePosition))
    {
        SetFinishStatus(true);
        return;
    }
}

void StartState::Update()
{
    sf::Vector2i mousePosition;
    sf::Event event;

    while (renderHelper->GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) renderHelper->GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed) CheckStartButtonPressed();
    }
}