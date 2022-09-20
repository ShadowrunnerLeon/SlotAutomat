#include "StopState.h"
#include "../../RenderHelper/RenderHelper.h"

StopState::StopState(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void StopState::Activate()
{
    for (auto& slot : renderHelper.GetSlots()) 
    {
        if (slot.getPosition().y >= 200.f) renderHelper.GetWindow().draw(slot);
    }

    sf::Vector2i mousePosition;
    sf::Event event;

    while (renderHelper.GetWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed) renderHelper.GetWindow().close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            mousePosition = sf::Mouse::getPosition(renderHelper.GetWindow());
            auto translatedMousePosition = renderHelper.GetWindow().mapPixelToCoords(mousePosition);
            if (renderHelper.GetStartButton().first.getGlobalBounds().contains(translatedMousePosition))
            {
                for (int i = 0; i < 5; ++i)
                {
                    sf::FloatRect redLineBounds = renderHelper.GetRedLine().getBounds();
                    sf::FloatRect slotBounds = renderHelper.GetSlot(i * 5).getGlobalBounds();
                    sf::Vector2f leftTop(slotBounds.left, slotBounds.top);
                    sf::Vector2f rightTop(slotBounds.left + slotBounds.width, slotBounds.top);
                    sf::Vector2f rightBottom(slotBounds.left + slotBounds.width, slotBounds.top + slotBounds.height);
                    sf::Vector2f leftBottom(slotBounds.left, slotBounds.top + slotBounds.height);

                    if (redLineBounds.contains(leftTop) && redLineBounds.contains(rightTop) && redLineBounds.contains(rightBottom) && redLineBounds.contains(leftBottom))
                    {
                        std::cout << "intersects" << std::endl;
                        for (int j = 0; j < 5; ++j)
                        {
                            for (int k = 0; k < 5; ++k)
                            {
                                if (renderHelper.GetSlot(i * 5 + j).getTexture() == &(renderHelper.GetTexture(k)))
                                {
                                    std::cout << "match textures" << std::endl;
                                    ++texturesMatchNumber[k];
                                    break;
                                }
                            }
                        }

                        int maxMatchNumber = 0;
                        for (int j = 0; j < 5; ++j)
                        {
                            maxMatchNumber = std::max(maxMatchNumber, texturesMatchNumber[j]);
                            // clear
                            texturesMatchNumber[j] = 0;
                        }

                        renderHelper.GetScoreInt() += maxMatchNumber * 500;
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
bool StopState::GetDeactivateStatus() { return deactivateFlag; }