#include "SpinState.h"

SpinState::SpinState(sf::Time _timer, float _spinSpeed) : timer(_timer), spinSpeed(_spinSpeed) 
{
    elapsedTime = sf::seconds(0);
}

void SpinState::Update()
{
    sf::Vector2i mousePosition;
    sf::Event event;
    sf::Clock clock;

    while (RenderHelper::GetInstance().GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            RenderHelper::GetInstance().GetWindow().close();
        }
        
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(RenderHelper::GetInstance().GetWindow());
            auto translatedMousePosition = RenderHelper::GetInstance().GetWindow().mapPixelToCoords(mousePosition);
            if (RenderHelper::GetInstance().GetStopButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                elapsedTime = sf::seconds(0);
                SetFinishStatus(true);
                return;
            }
        }
    }

    for (int i = 0; i < NUM_SLOTS; ++i)
    {
        if (RenderHelper::GetInstance().GetSlot(i * NUM_SLOTS).sprite.getPosition().y >= END_LINE_Y)
        {
            for (int j = 0; j < NUM_SLOTS; ++j)
            {
                int textureIndex = rand() % NUM_SLOTS;
                RenderHelper::GetInstance().GetSlot(i * NUM_SLOTS + j).sprite.setTexture(RenderHelper::GetInstance().GetTexture(textureIndex));
                RenderHelper::GetInstance().GetSlot(i * NUM_SLOTS + j).sprite.setPosition(START_LINE_X + j * 64.f, START_LINE_Y - i * 64.f);
                RenderHelper::GetInstance().SetTextureIndex(i * NUM_SLOTS + j, textureIndex);
            }
        }
    }

    for (auto& slot : RenderHelper::GetInstance().GetSlots()) 
    {
        slot.sprite.move(0.f, spinSpeed);
        if (slot.sprite.getPosition().y >= START_LINE_Y)
        {
            RenderHelper::GetInstance().GetWindow().draw(slot.sprite);
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