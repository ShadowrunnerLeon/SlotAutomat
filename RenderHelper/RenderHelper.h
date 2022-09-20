#ifndef _RENDER_HELPER_H_
#define _RENDER_HELPER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class RenderHelper
{
    private:
        std::vector<sf::Texture> textures = std::vector<sf::Texture>(5, sf::Texture());
        sf::Font font;
        sf::RenderWindow& window;
        std::pair<sf::Text, sf::VertexArray> startButton, stopButton;
        std::vector<sf::Sprite> slots;
        sf::VertexArray redLine = sf::VertexArray(sf::Lines, 8);
        sf::Text score;
        int scoreInteger = 0;

    public:
        RenderHelper(sf::RenderWindow& _window);
        std::pair<sf::Text, sf::VertexArray> renderButton(const sf::String &textString, float x, float y);
        void renderSlots();
        void renderRedLine();
        void renderScore();

        sf::RenderWindow& GetWindow();
        std::pair<sf::Text, sf::VertexArray>& GetStartButton();
        std::pair<sf::Text, sf::VertexArray>& GetStopButton();
        sf::Sprite& GetSlot(int index);
        std::vector<sf::Sprite>& GetSlots();
        sf::Texture& GetTexture(int index);
        sf::VertexArray& GetRedLine();
        sf::Text& GetScore();
        int& GetScoreInt(); 
};

#endif