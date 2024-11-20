#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "Graphics.h"
#include "Text.h"
#include "SceneLoader.h"
#include "Choice.h"

using namespace std;
// namespace std;


class Game
{
    private:
    //Private Variables

    sf::RenderWindow* window = nullptr;
    sf::Event event;   
    Graphics graphics;
    TextManager textManager;
    SceneLoader sceneLoader;
    ChoiceManager choiceManager;

    bool textElementsHidden = true;
    sf::Shader blurShader;
    sf::RectangleShape textElementsBG;
    float sceneTransferCooldown = 0.2;

    //Pointers
    Graphics* pGraphics = nullptr;
    TextManager* pTextManager = nullptr;
    ChoiceManager* pChoiceManager = nullptr;

    //Private Functions
    void initVariables();
    void initWindow();

    void showTextElements();
    void hideTextElements();

    public:
    //Constructors and Destructors
    Game();
    virtual ~Game();


    //Functions
    bool running();
    void pollEvents();
    void update();
    void renderSprites();
    void renderChoices();
    void renderTexts();
    void render();
};