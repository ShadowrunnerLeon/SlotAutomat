#ifndef _RENDER_HELPER_H_
#define _RENDER_HELPER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
struct SlotTextureIndex
{
    sf::Sprite sprite;
    int textureIndex;
    SlotTextureIndex(sf::Sprite _sprite, int _textureIndex) : sprite(_sprite), textureIndex(_textureIndex) {}
};

class RenderHelper
{
    private:
        std::vector<sf::Texture> textures;
        sf::Font font;
        sf::RenderWindow& window;
        std::pair<sf::Text, sf::VertexArray> startButton, stopButton;
        std::vector<SlotTextureIndex> slots;
        sf::VertexArray redLine;
        sf::Text score;
        int scoreInteger;

    public:
        RenderHelper(sf::RenderWindow& _window);
        std::pair<sf::Text, sf::VertexArray> RenderButton(const sf::String &textString, float x, float y) const;
        void RenderSlots();
        void RenderRedLine();
        void RenderScore();

        sf::RenderWindow& GetWindow();
        std::pair<sf::Text, sf::VertexArray>& GetStartButton();
        std::pair<sf::Text, sf::VertexArray>& GetStopButton();
        SlotTextureIndex& GetSlot(int index);
        std::vector<SlotTextureIndex>& GetSlots();
        void SetTextureIndex(int index, int value);
        sf::Texture& GetTexture(int index);
        sf::VertexArray& GetRedLine();
        sf::Text GetScore() const;
        void UpdateScore(int value);
};

#endif