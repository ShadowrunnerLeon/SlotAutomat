#include <SFML/Graphics.hpp>
#include <iostream>

static inline std::pair<sf::Text, sf::VertexArray> renderButton(sf::Font &font, const sf::String &textString, float x, float y) 
{
    sf::Text text;
    text.setFont(font);
    text.setString(textString);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);

    sf::FloatRect floatRect = text.getGlobalBounds();
    sf::VertexArray boundingRect(sf::Lines, 8);

    boundingRect[0].position = sf::Vector2f(floatRect.left - 5, floatRect.top - 5);
    boundingRect[1].position = sf::Vector2f(floatRect.left + floatRect.width + 5, floatRect.top - 5);
    boundingRect[2].position = sf::Vector2f(floatRect.left + floatRect.width + 5, floatRect.top - 5);
    boundingRect[3].position = sf::Vector2f(floatRect.left + floatRect.width + 5, floatRect.top + floatRect.height + 5);
    boundingRect[4].position = sf::Vector2f(floatRect.left + floatRect.width + 5, floatRect.top + floatRect.height + 5);
    boundingRect[5].position = sf::Vector2f(floatRect.left - 5, floatRect.top + floatRect.height + 5);
    boundingRect[6].position = sf::Vector2f(floatRect.left - 5, floatRect.top + floatRect.height + 5);
    boundingRect[7].position = sf::Vector2f(floatRect.left - 5, floatRect.top - 5);

    for (int i = 0; i < 8; ++i)
    {
        boundingRect[i].color = sf::Color::Red;
    }

    return std::make_pair(text, boundingRect);
}

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");

    sf::Font font;
    if (!font.loadFromFile("../resources/fonts/Oswald-Bold.ttf"))
    {
        std::cout << "load font: fail" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto startButton = renderButton(font, "START", 550.f, 150.f);
    auto stopButton = renderButton(font, "STOP", 550.f, 350.f);

    /************************************************************/

    sf::Texture texture;
    if (!texture.loadFromFile("../resources/img/smallIcon.png"))
    {
        std::cout << "load texture: fail" << std::endl;
        exit(EXIT_FAILURE);
    }

    sf::Sprite sprite[5];

    for (int i = 0; i < 5; ++i)
    {
        sprite[i].setTexture(texture);
        sprite[i].setPosition(100.f + i * 64.f, 0.f);
    }

    sf::Vector2i mousePosition;
    sf::FloatRect floatRect;
    bool isStarted = false;

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        window.draw(startButton.first);
        window.draw(startButton.second);
        window.draw(stopButton.first);
        window.draw(stopButton.second);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                mousePosition = sf::Mouse::getPosition(window);
                auto translatedMousePosition = window.mapPixelToCoords(mousePosition);
                if (startButton.first.getGlobalBounds().contains(translatedMousePosition))
                {
                    isStarted = true;
                }
                else if (stopButton.first.getGlobalBounds().contains(translatedMousePosition))
                {
                    isStarted = false;
                }
            }
        }

        if (sprite[0].getPosition().y >= 600.f)
        {
            for (int i = 0; i < 5; ++i) sprite[i].setPosition(100.f + i * 64.f, 0.f);
        }

        if (isStarted)
        {
            for (int i = 0; i < 5; ++i) sprite[i].move(0.f, 0.05);
        }

        for (int i = 0; i < 5; ++i) window.draw(sprite[i]);

        window.display();
    }
}