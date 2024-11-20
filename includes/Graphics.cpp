#include "Graphics.h"

Texture* Graphics::storeTexture(std::string filename)
{
    Texture* texture;
    texture = new Texture;
    texture->loadFromFile(filename);
    this->textures.push_back(texture);
    return texture;
}

Graphics::Graphics()
{
    this->windowDimensions = sf::Vector2u(1280, 720);
}

Graphics::~Graphics()
{
}

void Graphics::setBackground(std::string texturefilename)
{
    if (!this->backgroundTexture.loadFromFile(texturefilename))
    {
        std::cout << "Error Loading Texture!";
    }

    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->spriteQueue.push_back(backgroundSprite);
    std::cout << spriteQueue[0].getPosition().x;
}

void Graphics::drawSprite(std::string texturefilename, int xOffset, int yOffset, float xScale, float yScale)
{
       Sprite sprite;
       sprite.setTexture(*(this->storeTexture(texturefilename)));
       Vector2f offsetPosition = sf::Vector2f((this->backgroundSprite.getGlobalBounds().left + xOffset), (this->backgroundSprite.getGlobalBounds().top + yOffset));
       Vector2f spriteCenter = sf::Vector2f(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
       sprite.setOrigin(spriteCenter); // Sets the origin to the center of the sprite from top-left corner
       sprite.setPosition(offsetPosition); // Sets position of the sprite relative to the top-left corner of background image
       sprite.setScale(sf::Vector2f(xScale, yScale)); // Sets sprite scale 
       this->spriteQueue.push_back(sprite);
}

void Graphics::clearSpritesnTextures()
{
    for(auto texture: textures)
    {
        delete texture;
    }

    spriteQueue.clear();
}

sf::Vector2f Graphics::getBackgroundSize()
{
    sf::Vector2f bgSize = this->backgroundSprite.getGlobalBounds().getSize();
    return bgSize;
}

void Graphics::clearSpriteQueue()
{
    /*
        -Deletes all textures that were made to the heap
        -Removes all the pointers to said textures from <textures>
        -Removes all Sprites from <spriteQueue>

        ---------------------------------------------

        To clear old scene stuff
    */
   
    for (Texture* texture: this->textures)
    {
        delete texture;
    }
    this->spriteQueue.clear();
    this->textures.clear();
}
