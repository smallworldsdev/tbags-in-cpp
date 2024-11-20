#pragma once

#include <iostream>
#include <fstream>
#include "Graphics.h"
#include "Text.h"
#include "Choice.h"

class SceneLoader
{
    private:
    Graphics* graphics;
    TextManager* textManager;
    ChoiceManager* choiceManager;
    sf::RenderWindow* window;
    vector<string> splitString(std::string);

    public:
    SceneLoader();
    virtual ~SceneLoader();
    void setPointers(Graphics*, TextManager*, ChoiceManager*, sf::RenderWindow*);
    void loadScene(std::string);
    void loadNewScene(std::string);
    void clearScene();
};
