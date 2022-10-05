#include "SpinState.h"

SpinState::SpinState(RenderHelper& _renderHelper, sf::Time _timer, float _spinSpeed) : renderHelper(_renderHelper), timer(_timer), spinSpeed(_spinSpeed) 
{
    elapsedTime = sf::seconds(0);
}

void SpinState::Update()
{
    sf::Vector2i mousePosition;
    sf::Event event;
    sf::Clock clock;

    while (renderHelper.GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            renderHelper.GetWindow().close();
        }
        
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(renderHelper.GetWindow());
            auto translatedMousePosition = renderHelper.GetWindow().mapPixelToCoords(mousePosition);
            if (renderHelper.GetStopButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                elapsedTime = sf::seconds(0);
                SetFinishStatus(true);
                return;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (renderHelper.GetSlot(i * 5).sprite.getPosition().y >= 520.f)
        {
            for (int j = 0; j < 5; ++j)
            {
                int textureIndex = rand() % 5;
                renderHelper.GetSlot(i * 5 + j).sprite.setTexture(renderHelper.GetTexture(textureIndex));
                renderHelper.GetSlot(i * 5 + j).sprite.setPosition(100.f + j * 64.f, 200.f - i * 64.f);
                renderHelper.SetTextureIndex(i * 5 + j, textureIndex);
            }
        }
    }

    for (auto& slot : renderHelper.GetSlots()) 
    {
        slot.sprite.move(0.f, spinSpeed);
        if (slot.sprite.getPosition().y >= 200.f)
        {
            renderHelper.GetWindow().draw(slot.sprite);
        }
    }

    elapsedTime += clock.restart();
    if (elapsedTime >= timer)
    {
        elapsedTime = sf::seconds(0);
        std::cout << "timeout" << std::endl;
        SetFinishStatus(true);
    }
}