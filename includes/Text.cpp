#include "Text.h"

sf::Vector2f TextManager::findTextPosition()
{
    sf::Vector2f returnPosition = sf::Vector2f(50, 40);

    for (sf::Text* text: this->textQueue)
    {
        returnPosition.y += text->getGlobalBounds().height + this->textSeperation;
    }

    if (returnPosition.y + 60> this->textPositionLowerBound)
    {
        this->textPositionLowerBound = returnPosition.y + 60;
    }

    return returnPosition;
}

TextManager::TextManager()
{
    if(!this->font.loadFromFile("BerkshireSwash-Regular.ttf"))
    {
        cout << "Error" << endl;
        system("pause");
    }
}

TextManager::~TextManager()
{
}

void TextManager::setCharSize(int charSize)
{
    this->charSize = charSize;
}


void TextManager::addText(std::string textData)
{
    sf::Text* text = new sf::Text();
    text->setString(textData);
    text->setFont(this->font);
    text->setCharacterSize(this->charSize);
    text->setPosition(this->findTextPosition());
    this->textQueue.push_back(text);
}

void TextManager::clearTexts()
{
    /*
        -Deletes all instances of Text that were created to heap
        -Clears textQueue vector
    */

    for (sf::Text* text: this->textQueue)
    {   
        delete text;
    }

    this->textQueue.clear();
    this->textPositionLowerBound = 60;
}
