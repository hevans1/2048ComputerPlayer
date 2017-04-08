#ifndef BOARD_H
#define BOARD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <iostream>
#include <vector>

#include "RoundedRectangleShape.hpp"

#include "Tile.h"
#include "Boardspace.h"
#include "Score.h"
#include "Button.h"
#include "Utility.h"



class Board : public sf::Drawable
{
    public:
        /** Default constructor */
        Board();
        /** Default destructor */
        ~Board();

        enum Dir {
            Left = sf::Keyboard::Key::Left,
            Right = sf::Keyboard::Key::Right,
            Up = sf::Keyboard::Key::Up,
            Down = sf::Keyboard::Key::Down
        };

        void setFont(sf::Font& font);

        void Move(int direction);
        void MoveTile(Tile& tile, int direction);
        void SpawnTile();
        bool checkForLoss();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        int RandomInt(int min, int max);
    protected:

    private:
        sf::RoundedRectangleShape board;
        std::vector<Boardspace> boardspaces;
//        std::vector<std::vector<Tile>> tiles;
        std::vector<Tile> tiles;

        double tilePadding;
        double tileWidth;
};



#endif // BOARD_H
