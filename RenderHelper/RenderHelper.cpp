#include "RenderHelper.h"

RenderHelper::RenderHelper(sf::RenderWindow& _window) : window(_window) 
{
    if (!font.loadFromFile("../resources/fonts/Oswald-Bold.ttf"))
    {
        std::cout << "load font: fail" << std::endl;
        exit(EXIT_FAILURE);
    }

    startButton = renderButton("START", 550.f, 150.f);
    stopButton = renderButton("STOP", 550.f, 350.f);
}

std::pair<sf::Text, sf::VertexArray> RenderHelper::renderButton(const sf::String &textString, float x, float y)
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

void RenderHelper::renderSlots()
{
    for (int i = 0; i < 5; ++i)
    {
        std::string path("../resources/img/");
        path += std::to_string(i + 1);
        path += ".png";

        if (!textures[i].loadFromFile(path))
        {
            std::cout << "load texture: fail" << std::endl;
            exit(EXIT_FAILURE);
        }

        sf::Sprite sprite;
        sprite.setTexture(textures[i]);
        sprite.setPosition(100.f + i * 64.f, 0.f);
        slots.push_back(sprite);
    }
}

sf::RenderWindow& RenderHelper::GetWindow()
{
    return window;
}

std::pair<sf::Text, sf::VertexArray>& RenderHelper::GetStartButton()
{
    return startButton;
}

std::pair<sf::Text, sf::VertexArray>& RenderHelper::GetStopButton()
{
    return stopButton;
}

sf::Sprite& RenderHelper::GetSlot(int index)
{
    return slots[index];
}

sf::Texture& RenderHelper::GetTexture(int index)
{
    return textures[index];
}

int RenderHelper::GetNumber()
{
    return slots.size();
}

std::vector<sf::Sprite>& RenderHelper::GetSlots()
{
    return slots;
}