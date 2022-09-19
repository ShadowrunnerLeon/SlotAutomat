#include "SpinState.h"

SpinState::SpinState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void SpinState::Activate()
{
    sf::Vector2i mousePosition;
    sf::Event event;
    sf::Clock timer;

    std::cout << elapsedTime.asSeconds() << std::endl;

    if (elapsedTime >= sf::seconds(5))
    {
        elapsedTime = sf::seconds(0);
        std::cout << "timeout" << std::endl;
        deactivateFlag = true;
        return;
    }

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

    if (renderHelper.GetSlot(0).getPosition().y >= 600.f)
    {
        int size = renderHelper.GetSlots().size();
        for (int i = 0; i < size; ++i)
        {
            renderHelper.GetSlot(i).setTexture(renderHelper.GetTexture(rand() % size));
            renderHelper.GetSlot(i).setPosition(100.f + i * 64.f, 0.f);
        }
    }

    for (auto& slot : renderHelper.GetSlots()) 
    {
        slot.move(0.f, 0.1);
        renderHelper.GetWindow().draw(slot);
    }

    elapsedTime += timer.restart();
}

void SpinState::SetDeactivateStatus() { deactivateFlag = false; }
bool SpinState::GetDeactivateStatus() { return deactivateFlag; }