#include "includes/Game.h"

using namespace sf;

float fps = 60;

int main() 
{
    Game game;

    while (game.running())
    {
        game.update();

        game.render();

        sleep(Time(sf::seconds(1/fps)));
    }

    return 0;
}
