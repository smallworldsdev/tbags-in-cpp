#include "Game.h"

void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Text Adventure Game", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->graphics.windowDimensions = this->window->getSize();
    this->pGraphics = &(this->graphics);
    this->pTextManager = &(this->textManager);
    this->pChoiceManager = &(this->choiceManager);
    this->sceneLoader.setPointers(pGraphics, pTextManager, pChoiceManager, this->window);

    std::cout << "loading main scene" << std::endl;
    this->sceneLoader.loadScene("scenes/main.tbags"); // Loads main scene (aka first scene)
    std::cout << "completed loading main scene" << std::endl;

    // Load Shader
    if (sf::Shader::isAvailable())
    {
        if (!blurShader.loadFromFile("gaussianblur.frag", sf::Shader::Fragment))
        {
            std::cout << "Error loading blur shader!" << std::endl;
        }
    }
}

void Game::showTextElements()
{
    this->textElementsHidden = false;
}

void Game::hideTextElements()
{
    this->textElementsHidden = true;
}

Game::~Game()
{
    delete this->window;
}

bool Game::running()
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
            {
                switch (this->event.type)
                {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                
                case sf::Event::KeyPressed:
                    if (this->event.key.code == Keyboard::Escape)
                    {
                        this->window->close();
                        break;
                    }
                    else if(this->event.key.code == Keyboard::N)
                    {
                        std::cout << "N pressed" <<std::endl;
                        if  (this->textElementsHidden)
                        {
                            this->showTextElements();
                        }
                        else
                        {
                            this->hideTextElements();
                        }
                        std::cout << this->textElementsHidden << std::endl;
                    }
                
                default:
                    break;
                }
            }
}

void Game::update()
{
    /*
        -polls events

        Updates game logic
    */
    this->pollEvents();
    if (!this->textElementsHidden)
    {
        for (auto choice : this->choiceManager.choices)
        {
            std::string updateChoiceOutput = choice->updateChoice();
            if (updateChoiceOutput != "")
            {
                this->sceneLoader.loadNewScene(updateChoiceOutput);
                sf::sleep(sf::Time(sf::seconds(this->sceneTransferCooldown)));
                break;
            }
        }
    }
}

void Game::renderSprites()
{
    for(auto& sprite: graphics.spriteQueue)
    {
        if (this->textElementsHidden)
        {
            this->window->draw(sprite);
        }
        else
        {
            blurShader.setUniform("source", sf::Shader::CurrentTexture);
            blurShader.setUniform("offsetFactor", sf::Vector2f(0.0015, 0.0015));
            this->window->draw(sprite, &blurShader);
        }
    }
}

void Game::render()
{
    /*
        -clears window
        -draws to window
        -displays to window

        Renders stuff on to screen
    */

   //Clear
    this->window->clear(sf::Color::Black);

    //Draw here
    this->renderSprites();
    if (!this->textElementsHidden)
    {
        textElementsBG.setPosition(sf::Vector2f(40, 30));
        textElementsBG.setSize(sf::Vector2f(1200, 640));
        textElementsBG.setFillColor(sf::Color(60, 60, 60, 120));
        this->window->draw(textElementsBG);
        this->renderTexts();
        this->renderChoices();
    }

    //Display
    this->window->display();

}

void Game::renderChoices()
{
    for (auto choice: this->choiceManager.choices)
    {
        this->window->draw(choice->choiceText);
    }
}

void Game::renderTexts()
{
    for (sf::Text* text: this->textManager.textQueue)
    {
        this->window->draw(*text);
    }
}
