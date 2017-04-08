#include "Tile.h"

Tile::Tile() :
    value{2},
    visible{false},
    transition(0.5*0.5*60)
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

Tile::Tile(sf::Vector2f position, sf::Vector2f tileSize, std::tuple<int,int> homePosition) :
    value{2},
    visible{false},
    homePositionIndex(homePosition),
    homePositionPixels(position),
    transition(0.5*0.5*60)
{
    if (!font.loadFromFile("ClearSans-Regular.ttf"))
    {
        exit(EXIT_FAILURE);
    }

    // set tile characteristics
    tile.setFillColor(sf::Color(238, 228, 218)); // magic
    tile.setPosition(position);
    tile.setSize(tileSize);
    tile.setCornersRadius(tile.getSize().x/24); // magic
    tile.setCornerPointCount(10); // magic

    // set text characteristics
    text.setFont(font);
    text.setPosition(position);
    text.setCharacterSize(20); // magic
    text.setString("asdf");
    text.setFillColor(sf::Color::Black);
    text.setOutlineColor(sf::Color::Black);

//    text.setFont(font);
//    text.setFillColor(sf::Color::Black);
//    text.setOutlineColor(sf::Color::Black);
//    text.setPosition(position);
////    text.setPosition(sf::Vector2f(0,0));
//    text.setCharacterSize(30); // magic
//    text.setString("2");


    moveDistance = tileSize.x + tileSize.x/10; // magic, padding is 1/10 of width
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(tile, states);
//    target.draw(text, states);
}

void Tile::setVisible(bool b)
{
    visible = b;
}

bool Tile::getVisible()
{
    return visible;
}

void Tile::setText(std::string s)
{
    text.setString(s);
    this->updateText();
}

std::string Tile::getText()
{
    return text.getString();
}

void Tile::setColor(sf::Color color)
{
    tile.setFillColor(color);
}

sf::Color Tile::getColor()
{
    return tile.getFillColor();
}

void Tile::updateText()
{
    // set origin to corner of tile to reframe
    text.setOrigin(tile.getPosition());

    // shrink if too large
    while (text.getLocalBounds().width > 3/4 * tile.getLocalBounds().width)
        text.setCharacterSize(text.getCharacterSize()-2);

    // center
    sf::Vector2f position(
        tile.getLocalBounds().width/2 - text.getLocalBounds().width/2,
        tile.getLocalBounds().height/2 - text.getLocalBounds().height/2
    );
    text.setPosition(position);
}

void Tile::setFont(sf::Font& font)
{
    text.setFont(font);
}

sf::Vector2f Tile::getPosition()
{
    return tile.getPosition();
}

void Tile::calcTransition(std::tuple<int, int> end, bool merge)
{
    // if the tile is part of a merge
    // if the tile stays in place, increment value. else, remove.
    if (merge)
    {
        if (std::get<0>(end) == std::get<0>(homePositionIndex)
            && std::get<1>(end) == std::get<1>(homePositionIndex))
        {
            value_new = 2 * value;
        }
        else
        {
            visible = false;
        }
    }

    // calculate end in pixels
    sf::Vector2f endPosition(
        (std::get<1>(end) - std::get<1>(homePositionIndex)) * moveDistance + homePositionPixels.x,
        (std::get<0>(end) - std::get<0>(homePositionIndex)) * moveDistance + homePositionPixels.y
    );

//    int n = 0.5 * 0.5 * 60; // magic // seconds * 1/2 * frames per second // see constructor
    double dx = (endPosition.x - tile.getPosition().x) / transition.size();
    double dy = (endPosition.y - tile.getPosition().y) / transition.size();

    // calculate positions
    for (int ii{0}; ii<transition.size(); ++ii)
    {
        sf::Vector2f next(tile.getPosition().x + dx*ii, tile.getPosition().y + dy*ii);
        transition[ii] = next;
    }
}

void Tile::move(int index)
{
    tile.setPosition(transition[index]);
}

void Tile::updateAfterMove()
{
    value = value_new;
    visible = visible_new;

    text.setString(to_string(value));
    tile.setPosition(homePositionPixels);
}

template<typename T>
std::string Tile::to_string(const T& n) // util.cpp
{
    std::ostringstream stm;
    stm << n;
    return stm.str();
}
