#include "SpinState.h"

SpinState::SpinState(RenderHelper& _renderHelper, sf::Time _timer, float _spinSpeed) : State(_renderHelper), timer(_timer), spinSpeed(_spinSpeed) 
{
    elapsedTime = sf::seconds(0);
}

void SpinState::Update()
{
    sf::Vector2i mousePosition;
    sf::Event event;
    sf::Clock clock;

    while (GetRenderHelper().GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            GetRenderHelper().GetWindow().close();
        }
        
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(GetRenderHelper().GetWindow());
            auto translatedMousePosition = GetRenderHelper().GetWindow().mapPixelToCoords(mousePosition);
            if (GetRenderHelper().GetStopButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                elapsedTime = sf::seconds(0);
                SetFinishStatus(true);
                return;
            }
        }
    }

    for (int i = 0; i < NUM_SLOTS; ++i)
    {
        if (GetRenderHelper().GetSlot(i * NUM_SLOTS).sprite.getPosition().y >= END_LINE_Y)
        {
            for (int j = 0; j < NUM_SLOTS; ++j)
            {
                int textureIndex = rand() % NUM_SLOTS;
                GetRenderHelper().GetSlot(i * NUM_SLOTS + j).sprite.setTexture(GetRenderHelper().GetTexture(textureIndex));
                GetRenderHelper().GetSlot(i * NUM_SLOTS + j).sprite.setPosition(START_LINE_X + j * 64.f, START_LINE_Y - i * 64.f);
                GetRenderHelper().SetTextureIndex(i * NUM_SLOTS + j, textureIndex);
            }
        }
    }

    for (auto& slot : GetRenderHelper().GetSlots()) 
    {
        slot.sprite.move(0.f, spinSpeed);
        if (slot.sprite.getPosition().y >= START_LINE_Y)
        {
            GetRenderHelper().GetWindow().draw(slot.sprite);
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