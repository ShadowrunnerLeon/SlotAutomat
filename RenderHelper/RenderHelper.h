#ifndef _RENDER_HELPER_H_
#define _RENDER_HELPER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#define NUM_SLOTS 5
#define START_LINE_X 100.f 
#define START_LINE_Y 200.f
#define END_LINE_Y 520.f

struct SlotTextureIndex
{
    sf::Sprite sprite;
    int textureIndex;
    SlotTextureIndex() = default;
    SlotTextureIndex(sf::Sprite _sprite, int _textureIndex) : sprite(_sprite), textureIndex(_textureIndex) {}
};

struct Button
{
    sf::Text text;
    sf::VertexArray vertexArray;
    Button() = default;
    Button(sf::Text _text, sf::VertexArray _vertexArray) : text(_text), vertexArray(_vertexArray) {}
};

class RenderHelper
{
    private:
        std::vector<sf::Texture> textures;
        sf::Font font;
        sf::RenderWindow window;
        Button startButton, stopButton;
        std::vector<SlotTextureIndex> slots;

        sf::VertexArray redLine;
        sf::Text score;
        int scoreInteger;

    public:
        RenderHelper();
        Button RenderButton(const sf::String &textString, float x, float y) const;
        void RenderSlots();
        void RenderRedLine();
        void RenderScore();

        sf::RenderWindow& GetWindow();
        Button& GetStartButton();
        Button& GetStopButton();
        SlotTextureIndex& GetSlot(int index);
        std::vector<SlotTextureIndex>& GetSlots();
        void SetTextureIndex(int index, int value);
        sf::Texture& GetTexture(int index);
        sf::VertexArray& GetRedLine();
        sf::Text GetScore() const;
        void UpdateScore(int value);
};

#endif