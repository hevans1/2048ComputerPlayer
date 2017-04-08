#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "RoundedRectangleShape.hpp"

#include <string>
#include <sstream>
#include <utility>

class Tile : public sf::Drawable
{
    public:
        Tile();
        ~Tile();

        Tile(sf::Vector2f position, sf::Vector2f tileSize, std::tuple<int,int> homePosition);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void updateText();

        void calcTransition(std::tuple<int, int> end, bool merge);
        void move(int index);
        void updateAfterMove();

        void setVisible(bool b);
        bool getVisible();

        void setText(std::string s);
        std::string getText();

        void setColor(sf::Color color);
        sf::Color getColor();

        void setFont(sf::Font& font);

        sf::Vector2f getPosition();

        template<typename T>
        std::string to_string(const T& n); // util.cpp

    protected:

    private:
        int value;
        bool visible;
        std::tuple<int,int> homePositionIndex;
        sf::Vector2f homePositionPixels;

        std::vector<sf::Vector2f> transition;
        int value_new;
        bool visible_new;

        double moveDistance;

        sf::RoundedRectangleShape tile;
        sf::Text text;
        sf::Font font;
};

#endif // TILE_H
