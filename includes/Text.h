#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

class TextManager
{
    private:
    sf::Font font;
    int charSize = 36;
    float textSeperation = 15;

    sf::Vector2f findTextPosition();

    public:
    vector<sf::Text*> textQueue; 
    float textPositionLowerBound = 60;
    TextManager();
    virtual ~TextManager();

    void setCharSize(int);
    void addText(std::string);
    void clearTexts();
};