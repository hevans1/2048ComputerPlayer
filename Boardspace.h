#ifndef BOARDSPACE_H
#define BOARDSPACE_H

#include <SFML/Graphics.hpp>

#include "RoundedRectangleShape.hpp"

class Boardspace : public sf::Drawable
{
    public:
        Boardspace();
        ~Boardspace();

        Boardspace(sf::Vector2f position, sf::Vector2f size);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    protected:

    private:
        sf::RoundedRectangleShape boardspace;
};

#endif // BOARDSPACE_H
