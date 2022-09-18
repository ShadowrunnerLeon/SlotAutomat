#ifndef _RENDER_HELPER_H_
#define _RENDER_HELPER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class RenderHelper
{
    private:
        sf::Font font;
        sf::RenderWindow& window;
        std::pair<sf::Text, sf::VertexArray> startButton, stopButton;
        std::vector<sf::Sprite> slots;

    public:
        RenderHelper(sf::RenderWindow& _window);
        std::pair<sf::Text, sf::VertexArray> renderButton(const sf::String &textString, float x, float y);
        void renderSlots();

        sf::RenderWindow& GetWindow();
        std::pair<sf::Text, sf::VertexArray>& GetStartButton();
        std::pair<sf::Text, sf::VertexArray>& GetStopButton();
        std::vector<sf::Sprite>& GetSlots();
        
};

#endif