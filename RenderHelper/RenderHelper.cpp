#include "RenderHelper.h"

RenderHelper::RenderHelper(sf::RenderWindow& _window) : window(_window) 
{
    if (!font.loadFromFile("../resources/fonts/Oswald-Bold.ttf"))
    {
        std::cout << "load font: fail" << std::endl;
        exit(EXIT_FAILURE);
    }

    startButton = RenderButton("START", 550.f, 150.f);
    stopButton = RenderButton("STOP", 550.f, 350.f);
    textures = std::vector<sf::Texture>(5, sf::Texture());
    redLine = sf::VertexArray(sf::Lines, 8);
    scoreInteger = 0;
}

std::pair<sf::Text, sf::VertexArray> RenderHelper::RenderButton(const sf::String &textString, float x, float y) const
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

void RenderHelper::RenderSlots()
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
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            sf::Sprite sprite;
            int textureIndex = rand() % 5;
            sprite.setTexture(textures[textureIndex]);
            sprite.setPosition(100.f + j * 64.f, 200.f - i * 64.f);
            slots.push_back(SlotTextureIndex(sprite, textureIndex));
        }
    }
}

void RenderHelper::RenderRedLine()
{
    float top = 328.f;
    float left = 100.f;
    float height = 64.f;
    float width = 320.f;

    redLine[0].position = sf::Vector2f(left - 10.f, top - 10.f);
    redLine[1].position = sf::Vector2f(left + 10.f + width, top - 10.f);
    redLine[2].position = sf::Vector2f(left + 10.f + width, top - 10.f);
    redLine[3].position = sf::Vector2f(left + 10.f + width, top + height + 10.f);
    redLine[4].position = sf::Vector2f(left + 10.f + width, top + height + 10.f);
    redLine[5].position = sf::Vector2f(left - 10.f, top + height + 10.f);
    redLine[6].position = sf::Vector2f(left - 10.f, top + height + 10.f);
    redLine[7].position = sf::Vector2f(left - 10.f, top - 10.f);

    for (int i = 0; i < 8; ++i)
    {
        redLine[i].color = sf::Color::Red;
    }
}

void RenderHelper::RenderScore()
{
    score.setFont(font);
    score.setString("0");
    score.setCharacterSize(48);
    score.setFillColor(sf::Color::White);
    score.setPosition(550.f, 50.f);
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

SlotTextureIndex& RenderHelper::GetSlot(int index)
{
    return slots[index];
}

sf::Texture& RenderHelper::GetTexture(int index)
{
    return textures[index];
}

std::vector<SlotTextureIndex>& RenderHelper::GetSlots()
{
    return slots;
}

void RenderHelper::SetTextureIndex(int index, int value)
{
    slots[index].textureIndex = value;
}

sf::VertexArray& RenderHelper::GetRedLine()
{
    return redLine;
}

sf::Text& RenderHelper::GetScore()
{
    return score;
}

int RenderHelper::GetScoreInt() const
{
    return scoreInteger;
}

void RenderHelper::UpdateScoreInt(int value)
{
    scoreInteger += value;
}