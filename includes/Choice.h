#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Button
{
    private:
    sf::IntRect buttonRect;
    sf::RenderWindow* window;

    public:
    bool isHovering = false;
    bool isClicked = false;

    Button();
    virtual ~Button();

    void updateButtonProperties(int xOffset, int yOffset, float, float, sf::RenderWindow*);
    bool isItHovering();
    bool isItClicked();
    void buttonUpdate();
};



class Choice
{
    private:
    Button button;
    sf::Font choiceFont;
    std::string choiceSceneFile;
    sf::Color hoverColor = sf::Color(217, 46, 217, 255);
    sf::Color clickColor = sf::Color(204, 37, 179, 255);

    public:
    sf::Text choiceText;

    Choice(std::string, std::string, int, int, sf::RenderWindow*);
    virtual ~Choice();
    std::string updateChoice();
};


class ChoiceManager
{
    private:
    float choiceSeperation = 25;

    public:
    vector<Choice*> choices;

    ChoiceManager();
    virtual ~ChoiceManager();
    void addChoice(std::string, std::string, int, int, sf::RenderWindow*);
    void clearChoices();
    float choiceXPosition();
};
