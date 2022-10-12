#include "SpinState.h"

SpinState::SpinState(RenderHelper* _renderHelper, sf::Time _timer, float _spinSpeed) : timer(_timer), spinSpeed(_spinSpeed) 
{
    renderHelper = _renderHelper;
    elapsedTime = sf::seconds(0);
}

void SpinState::Update()
{
    sf::Vector2i mousePosition;
    sf::Event event;
    sf::Clock clock;

    while (renderHelper->GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            renderHelper->GetWindow().close();
        }
        
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(renderHelper->GetWindow());
            auto translatedMousePosition = renderHelper->GetWindow().mapPixelToCoords(mousePosition);
            if (renderHelper->GetStopButton().text.getGlobalBounds().contains(translatedMousePosition))
            {
                elapsedTime = sf::seconds(0);
                SetFinishStatus(true);
                return;
            }
        }
    }

    for (int i = 0; i < NUM_SLOTS; ++i)
    {
        if (renderHelper->GetSlot(i * NUM_SLOTS).sprite.getPosition().y >= END_LINE_Y)
        {
            for (int j = 0; j < NUM_SLOTS; ++j)
            {
                int textureIndex = rand() % NUM_SLOTS;
                renderHelper->GetSlot(i * NUM_SLOTS + j).sprite.setTexture(renderHelper->GetTexture(textureIndex));
                renderHelper->GetSlot(i * NUM_SLOTS + j).sprite.setPosition(START_LINE_X + j * 64.f, START_LINE_Y - i * 64.f);
                renderHelper->SetTextureIndex(i * NUM_SLOTS + j, textureIndex);
            }
        }
    }

    for (auto& slot : renderHelper->GetSlots()) 
    {
        slot.sprite.move(0.f, spinSpeed);
        if (slot.sprite.getPosition().y >= START_LINE_Y)
        {
            renderHelper->GetWindow().draw(slot.sprite);
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