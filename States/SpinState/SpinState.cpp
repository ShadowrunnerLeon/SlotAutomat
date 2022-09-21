#include "SpinState.h"

SpinState::SpinState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void SpinState::Activate()
{
    sf::Vector2i mousePosition;
    sf::Event event;
    sf::Clock timer;

    //std::cout << elapsedTime.asSeconds() << std::endl;

    while (renderHelper.GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) renderHelper.GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(renderHelper.GetWindow());
            auto translatedMousePosition = renderHelper.GetWindow().mapPixelToCoords(mousePosition);
            if (renderHelper.GetStopButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                elapsedTime = sf::seconds(0);
                deactivateFlag = true;
                return;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (renderHelper.GetSlot(i * 5).first.getPosition().y >= 520.f)
        {
            for (int j = 0; j < 5; ++j)
            {
                int textureIndex = rand() % 5;
                renderHelper.GetSlot(i * 5 + j).first.setTexture(renderHelper.GetTexture(textureIndex));
                renderHelper.GetSlot(i * 5 + j).first.setPosition(100.f + j * 64.f, 200.f - i * 64.f);
                renderHelper.SetTextureIndex(i * 5 + j, textureIndex);
            }
        }
    }

    for (auto& slot : renderHelper.GetSlots()) 
    {
        slot.first.move(0.f, 0.1);
        if (slot.first.getPosition().y >= 200.f) renderHelper.GetWindow().draw(slot.first);
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