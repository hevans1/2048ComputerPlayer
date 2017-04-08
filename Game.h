#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Board.h"

class Game
{
    public:
        /** Default constructor */
        Game();
        /** Default destructor */
        ~Game();

        Game(int width, int height);

        bool isAlive();

        void draw();

        bool pollEvent(sf::Event& event);

        void processEvent(sf::Event event);
        void processKeyReleased(sf::Event event);
        void processMouseButtonReleased(sf::Event event);

    private:
        sf::RenderWindow window;
        Board board;
        Score score;
        Score highScore;
        Button newGame;
        Button run_pause;

        sf::Font font;
        sf::Text text;
};

#endif // GAME_H
