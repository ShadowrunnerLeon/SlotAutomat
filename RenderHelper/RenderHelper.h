#ifndef _RENDER_HELPER_H_
#define _RENDER_HELPER_H_

#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(800, 600), "Window");

class RenderHelper
{
    private:
        sf::Font font;

    public:
        RenderHelper(sf::Font& _font);
        std::pair<sf::Text, sf::VertexArray> renderButton(const sf::String &textString, float x, float y);
        void renderSlots();
        
};

#endif