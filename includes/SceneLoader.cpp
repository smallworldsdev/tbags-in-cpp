#include "SceneLoader.h"

void SceneLoader::loadScene(std::string filename)
{
    std::cout << "loading scene: " << filename << std::endl;
    ifstream sceneFile(filename);
    string programLine;

    while(getline(sceneFile, programLine))
    {
        vector<string> wordVector = this->splitString(programLine);

        if (wordVector[0] == "G")
        {
            std::cout << "graphics command running" << std::endl;
            if(wordVector[1] == "BG")
            {
                std::cout << "bg command running" << std::endl;
                if (wordVector.size() == 3)
                {
                    cout << "bg file: " << wordVector[2] << endl;
                    this->graphics->setBackground(wordVector[2]);
                }
                else
                {
                    std::cout << "error, invalid number of arguments for BG" << std::endl;
                }
            }

            else if (wordVector[1] == "DRAW")
            {
                std::cout << "draw command running" << std::endl;
                if (wordVector.size() == 5)
                {
                    std::cout << "draw type 1" << std::endl;
                    this->graphics->drawSprite(wordVector[2], stoi(wordVector[3]), stoi(wordVector[4]));
                }
                else if (wordVector.size() == 7)
                {
                    std::cout << "draw type 2" << std::endl;
                    this->graphics->drawSprite(wordVector[2], stoi(wordVector[3]), stoi(wordVector[4]), stof(wordVector[5]), stof(wordVector[6]));
                }
                else
                {
                    std::cout << "error, invalid number of arguments for DRAW" << std::endl;
                }
            }
        }

        else if(wordVector[0] == "T")
        {
            std::cout << "text command running" << std::endl;
            if (wordVector.size() == 2)
            {
                std::cout << "text type 1" << std::endl;
                this->textManager->addText(wordVector[1]);
            }
            
            else if (wordVector.size() == 3)
            {
                std::cout << "text type 2" << std::endl;
                this->textManager->addText(wordVector[1]);
                this->textManager->setCharSize(stoi(wordVector[2]));
            }

            else
            {
                std::cout << "error, invalid number of arguments for T" << std::endl;
            }
        }

        else if (wordVector[0] == "C")
        {
            std::cout << "choice command running" << std::endl;
            float choicePositionX = this->choiceManager->choiceXPosition();
            sf::Vector2f chociePosition = sf::Vector2f(choicePositionX, (this->textManager->textPositionLowerBound + 10));
            this->choiceManager->addChoice(wordVector[1], wordVector[2], chociePosition.x, chociePosition.y, this->window);
        }

        else
        {
            std::cout << "Invalid Command!, try {G: Graphics, T: Text, C: Choice, W: Wait}" << std::endl;
        }
    }

    sceneFile.close();
}

void SceneLoader::loadNewScene(std::string newSceneFile)
{
    this->clearScene();
    this->loadScene(newSceneFile);
}

void SceneLoader::clearScene()
{
    /*
        Remove all the old scene stuff
        -Free Images
        -Free Choices
        -Free Texts
    */

   this->graphics->clearSpriteQueue();
   this->choiceManager->clearChoices();
   this->textManager->clearTexts();
}

vector<string> SceneLoader::splitString(std::string stringToSplit)
{
    vector<string> returnVector;
    string word = "";
    bool inQuotes = false;

    for(auto ch: stringToSplit)
    {
        if(ch == ' ' && !inQuotes)
        {
            returnVector.push_back(word);
            word = "";
        }
        else if (ch == '\"')
        {
            if (inQuotes)
            {
                inQuotes = false;
            }
            else
            {
                inQuotes = true;
            }
        }
        else
        {
            word += ch;
        }
    }

    returnVector.push_back(word);
    return returnVector;
}

SceneLoader::SceneLoader()
{
    std::cout << "Scene Loader loaded" << std::endl;
}

SceneLoader::~SceneLoader()
{

}

void SceneLoader::setPointers(Graphics* graphics, TextManager* textManager, ChoiceManager* choiceManager, sf::RenderWindow* window)
{
    this->graphics = graphics;
    this->textManager = textManager;
    this->choiceManager = choiceManager;
    this->window = window;
}
