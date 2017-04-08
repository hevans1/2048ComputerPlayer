#include "Score.h"

Score::Score()
{
    //ctor
}

Score::~Score()
{
    //dtor
}

void Score::setTitle(std::string str)
{
    title.setString(str);
}

void Score::setScore(std::string str)
{
    score.setString(str);
}

void Score::setFont(sf::Font& font)
{
    this->setTitleFont(font);
    this->setScoreFont(font);
}

void Score::setTitleFont(sf::Font& font)
{
    title.setFont(font);
}

void Score::setScoreFont(sf::Font& font)
{
    score.setFont(font);
}

std::string Score::getTitle()
{
    return title.getString();
}

std::string Score::getScore()
{
    return score.getString();
}
