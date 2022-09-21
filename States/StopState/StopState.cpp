#include "StopState.h"
#include "../../RenderHelper/RenderHelper.h"

StopState::StopState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void StopState::Activate()
{
    for (auto& slot : renderHelper.GetSlots()) 
    {
        if (slot.sprite.getPosition().y >= 200.f)
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

                for (int i = 0; i < 5; ++i)
                {
                    sf::FloatRect slotBounds = renderHelper.GetSlot(i * 5).sprite.getGlobalBounds();
                    sf::Vector2f leftTop(slotBounds.left, slotBounds.top);
                    sf::Vector2f rightTop(slotBounds.left + slotBounds.width, slotBounds.top);
                    sf::Vector2f rightBottom(slotBounds.left + slotBounds.width, slotBounds.top + slotBounds.height);
                    sf::Vector2f leftBottom(slotBounds.left, slotBounds.top + slotBounds.height);

                    if (redLineBounds.contains(leftTop) && redLineBounds.contains(rightTop) && redLineBounds.contains(rightBottom) && redLineBounds.contains(leftBottom))
                    {
                        int texturesNumber[5] = {0, 0, 0, 0, 0};
                        int maxMatchTexturesNumber = 0;
                        
                        std::cout << "stop " << i << ": ";
                        for (int j = 0; j < 5; ++j)
                        {
                            int textureIndex = renderHelper.GetSlot(i * 5 + j).textureIndex;
                            ++texturesNumber[textureIndex];
                            maxMatchTexturesNumber = std::max(maxMatchTexturesNumber, texturesNumber[textureIndex]);
                            std::cout << textureIndex << " ";
                        }

                        std::cout << std::endl;

                        renderHelper.UpdateScoreInt(maxMatchTexturesNumber * 500);
                        renderHelper.GetScore().setString(std::to_string(renderHelper.GetScoreInt()));

                        break;
                    }
                }

                deactivateFlag = true;
                return;
            }
        }
    } 
}

void StopState::SetDeactivateStatus() { deactivateFlag = false; }
bool StopState::GetDeactivateStatus() const { return deactivateFlag; }