#include "SpinState.h"

SpinState::SpinState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void SpinState::Activate()
{
    sf::Vector2i mousePosition;
    sf::Event event;
    sf::Clock timer;

    std::cout << elapsedTime.asSeconds() << std::endl;

    while (renderHelper.GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) renderHelper.GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(renderHelper.GetWindow());
            auto translatedMousePosition = renderHelper.GetWindow().mapPixelToCoords(mousePosition);
            if (renderHelper.GetStopButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                deactivateFlag = true;
                break;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (renderHelper.GetSlot(i * 5).getPosition().y >= 520.f)
        {
            for (int j = 0; j < 5; ++j)
            {
                renderHelper.GetSlot(i * 5 + j).setTexture(renderHelper.GetTexture(rand() % 5));
                renderHelper.GetSlot(i * 5 + j).setPosition(100.f + j * 64.f, 200.f - i * 64.f);
            }
        }
    }

    for (auto& slot : renderHelper.GetSlots()) 
    {
        slot.move(0.f, 0.1);
        if (slot.getPosition().y >= 200.f) renderHelper.GetWindow().draw(slot);
    }

    elapsedTime += timer.restart();
    if (elapsedTime >= sf::seconds(5))
    {
        elapsedTime = sf::seconds(0);
        std::cout << "timeout" << std::endl;
        deactivateFlag = true;
    }
}

void SpinState::SetDeactivateStatus() { deactivateFlag = false; }
bool SpinState::GetDeactivateStatus() { return deactivateFlag; }