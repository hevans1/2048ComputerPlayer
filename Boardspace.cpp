#include "Boardspace.h"

Boardspace::Boardspace()
{
//    boardspace.setFillColor(sf::Color(205, 193, 180));
//    boardspace.setSize(sf::Vector2f(118.75, 118.75));
}

Boardspace::Boardspace(sf::Vector2f position, sf::Vector2f size)
{
    boardspace.setFillColor(sf::Color(205, 193, 180)); // magic
    boardspace.setSize(size);
    boardspace.setPosition(position);
    boardspace.setCornersRadius(boardspace.getSize().x/24); // magic
    boardspace.setCornerPointCount(10); // magic
}

Boardspace::~Boardspace()
{
    //dtor
}

void Boardspace::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(boardspace, states);
}
