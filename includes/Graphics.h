#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
// namespace sf;

class Graphics
{
    private:
    Sprite backgroundSprite;
    std::vector<Texture*> textures;
    Texture backgroundTexture;

    Texture* storeTexture(std::string);

    public:
    std::vector<Sprite> spriteQueue;
    sf::Vector2u windowDimensions;

    Graphics();
    virtual ~Graphics();

    void setBackground(std::string);
    void drawSprite(std::string, int xOffset = 0, int yOffset = 0, float xScale = 1, float yScale = 1);
    void clearSpritesnTextures();
    sf::Vector2f getBackgroundSize();
    void clearSpriteQueue();
};
