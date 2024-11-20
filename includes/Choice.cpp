#include "Choice.h"

ChoiceManager::ChoiceManager()
{

}

ChoiceManager::~ChoiceManager()
{

}

void ChoiceManager::addChoice(std::string choiceText, std::string choiceSceneFile, int xOffset, int yOffset, sf::RenderWindow* window)
{
    Choice* choice = nullptr;
    choice = new Choice(choiceText, choiceSceneFile, xOffset, yOffset, window);
    choices.push_back(choice);
}

void ChoiceManager::clearChoices()
{
    /*
        -Deletes all instances of Choice that were created to heap
        -Clears choices vector
    */

    for (Choice* choice: choices)
    {
        delete choice;
    }

    this->choices.clear();
}

float ChoiceManager::choiceXPosition()
{
    float xPosition = 0;

    for (Choice* choice: choices)
    {
        xPosition = choice->choiceText.getGlobalBounds().left + choice->choiceText.getGlobalBounds().width + this->choiceSeperation;
    }

    if (xPosition == 0)
    {
        xPosition = 50;
    }

    return xPosition;
}

Choice::Choice(std::string choiceText, std::string choiceSceneFile, int xOffset, int yOffset, sf::RenderWindow* window)
{
    if(!this->choiceFont.loadFromFile("BerkshireSwash-Regular.ttf"))
    {
        cout << "--Error loading font!--" << endl;
        system("pause");
    }
    this->choiceText.setFont(this->choiceFont);
    this->choiceText.setCharacterSize(32);
    this->choiceText.setPosition(sf::Vector2f(xOffset, yOffset));

    this->choiceText.setString(">>" + choiceText);

    sf::Vector2f textBounds = sf::Vector2f((this->choiceText.getGlobalBounds().width), (this->choiceText.getGlobalBounds().height));
    this->button.updateButtonProperties(xOffset - 10, yOffset - 10, textBounds.x + 20, textBounds.y + 20, window); // Placing button class offset by 10 to left and increased width and height by 20 to create padding effect
    this->choiceSceneFile = choiceSceneFile;
}

Choice::~Choice()
{

}

std::string Choice::updateChoice()
{
    this->button.buttonUpdate();

    if (this->button.isHovering)
    {
        this->choiceText.setFillColor(this->hoverColor);
    }
    else
    {
        this->choiceText.setFillColor(sf::Color(255, 255, 255, 255));
    }

    if (this->button.isClicked)
    {
        /*
            Load New Scene through SceneLoader...
        */
       this->choiceText.setFillColor(this->clickColor);

       return this->choiceSceneFile;
    }

    return "";
}

Button::Button()
{

}

Button::~Button()
{

}

void Button::updateButtonProperties(int xOffset, int yOffset, float xSize, float ySize, sf::RenderWindow* window)
{
    this->buttonRect.left = xOffset;
    this->buttonRect.top = yOffset;
    this->buttonRect.width = xSize;
    this->buttonRect.height = ySize;
    this->window = window;
}

bool Button::isItHovering()
{
    if (this->buttonRect.contains(sf::Mouse::getPosition(*(this->window))))
    {
        this->isHovering = true;
        return true;
    }

    this->isHovering = false;
    return false;
}

bool Button::isItClicked()
{
    if (this->isHovering && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        this->isClicked = true;
        return true;
    }

    this->isClicked = false;
    return false;
}

void Button::buttonUpdate()
{
    this->isItHovering();
    this->isItClicked();
}
