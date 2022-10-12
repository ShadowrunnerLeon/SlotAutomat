#include "StopState.h"

StopState::StopState(RenderHelper* _renderHelper)
{
    renderHelper = _renderHelper;
}

bool StopState::IsStopButtonPressed()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(renderHelper->GetWindow());
    auto translatedMousePosition = renderHelper->GetWindow().mapPixelToCoords(mousePosition);
    return renderHelper->GetStartButton().text.getGlobalBounds().contains(translatedMousePosition);
}

bool StopState::SlotsInBounds(int range) const 
{
    sf::FloatRect slotBounds = renderHelper->GetSlot(range * NUM_SLOTS).sprite.getGlobalBounds(); 
    return slotBounds.left >= 90.f && slotBounds.top >= 318.f && slotBounds.left + slotBounds.width <= 90.f + 340.f && slotBounds.top + slotBounds.height <= 84.f + 318.f;
}

void StopState::CalculateScore(int range)
{
    int texturesNumber[NUM_SLOTS] = {0, 0, 0, 0, 0};
    int maxMatchTexturesNumber = 0;
                        
    for (int j = 0; j < NUM_SLOTS; ++j)
    {
        int textureIndex = renderHelper->GetSlot(range * NUM_SLOTS + j).textureIndex;
        ++texturesNumber[textureIndex];
        maxMatchTexturesNumber = std::max(maxMatchTexturesNumber, texturesNumber[textureIndex]);
    }

    renderHelper->UpdateScore(maxMatchTexturesNumber * 500);
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
    for (auto& slot : renderHelper->GetSlots()) 
    {
        if (slot.sprite.getPosition().y >= START_LINE_Y)
        {
            renderHelper->GetWindow().draw(slot.sprite);
        }
    }

    sf::Event event;

    while (renderHelper->GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) renderHelper->GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed && IsStopButtonPressed())
        {
            FindSlotsInBounds();
            SetFinishStatus(true);
            return;
        }
    } 
}