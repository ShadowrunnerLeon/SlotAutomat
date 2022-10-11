#include "StopState.h"

bool StopState::IsStopButtonPressed()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(RenderHelper::GetInstance().GetWindow());
    auto translatedMousePosition = RenderHelper::GetInstance().GetWindow().mapPixelToCoords(mousePosition);
    return RenderHelper::GetInstance().GetStartButton().first.getGlobalBounds().contains(translatedMousePosition);
}

bool StopState::SlotsInBounds(int range) const 
{
    sf::FloatRect slotBounds = RenderHelper::GetInstance().GetSlot(range * NUM_SLOTS).sprite.getGlobalBounds(); 
    return slotBounds.left >= 90.f && slotBounds.top >= 318.f && slotBounds.left + slotBounds.width <= 90.f + 340.f && slotBounds.top + slotBounds.height <= 84.f + 318.f;
}

void StopState::CalculateScore(int range)
{
    int texturesNumber[NUM_SLOTS] = {0, 0, 0, 0, 0};
    int maxMatchTexturesNumber = 0;
                        
    for (int j = 0; j < NUM_SLOTS; ++j)
    {
        int textureIndex = RenderHelper::GetInstance().GetSlot(range * NUM_SLOTS + j).textureIndex;
        ++texturesNumber[textureIndex];
        maxMatchTexturesNumber = std::max(maxMatchTexturesNumber, texturesNumber[textureIndex]);
    }

    RenderHelper::GetInstance().UpdateScore(maxMatchTexturesNumber * 500);
}

void StopState::FindSlotsInBounds()
{
    for (int i = 4; i >= 0; --i)
    {
        if (SlotsInBounds(i)) 
        { 
            CalculateScore(i);
            break;
        }
    }
}

void StopState::Update()
{
    for (auto& slot : RenderHelper::GetInstance().GetSlots()) 
    {
        if (slot.sprite.getPosition().y >= START_LINE_Y)
        {
            RenderHelper::GetInstance().GetWindow().draw(slot.sprite);
        }
    }

    sf::Event event;

    while (RenderHelper::GetInstance().GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) RenderHelper::GetInstance().GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed && IsStopButtonPressed())
        {
            FindSlotsInBounds();
            SetFinishStatus(true);
            return;
        }
    } 
}