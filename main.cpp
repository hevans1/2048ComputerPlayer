#include <main.h>

int main()
{
    Game game;

    while (game.isAlive())
    {
        sf::Event event;
        while (game.pollEvent(event))
        {
            game.processEvent(event);
        }

        game.draw();
    }

    return 0;
}


