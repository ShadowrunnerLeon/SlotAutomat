#include "StopState.h"
#include "../../RenderHelper/RenderHelper.h"

StopState::StopState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void StopState::Update()
{
    for (auto& slot : renderHelper.GetSlots()) 
    {
        if (slot.sprite.getPosition().y >= START_LINE_Y)
        {
            renderHelper.GetWindow().draw(slot.sprite);
        }
    }

    sf::Vector2i mousePosition;
    sf::Event event;

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
            if (renderHelper.GetStartButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                sf::FloatRect redLineBounds = renderHelper.GetRedLine().getBounds();

                for (int i = 4; i >= 0; --i)
                {
                    sf::FloatRect slotBounds = renderHelper.GetSlot(i * NUM_SLOTS).sprite.getGlobalBounds();

                    if (slotBounds.left >= 90.f && slotBounds.top >= 318.f && slotBounds.left + slotBounds.width <= 90.f + 340.f && slotBounds.top + slotBounds.height <= 84.f + 318.f)
                    {
                        int texturesNumber[NUM_SLOTS] = {0, 0, 0, 0, 0};
                        int maxMatchTexturesNumber = 0;
                        
                        for (int j = 0; j < NUM_SLOTS; ++j)
                        {
                            int textureIndex = renderHelper.GetSlot(i * NUM_SLOTS + j).textureIndex;
                            ++texturesNumber[textureIndex];
                            maxMatchTexturesNumber = std::max(maxMatchTexturesNumber, texturesNumber[textureIndex]);
                        }

                        renderHelper.UpdateScore(maxMatchTexturesNumber * 500);

                        break;
                    }
                }

                SetFinishStatus(true);
                return;
            }
        }
    } 
}