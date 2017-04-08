#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <string>


class Score : public sf::RectangleShape
{
    public:
        Score();
        ~Score();

        void setTitle(std::string title);
        void setScore(std::string score);

        std::string getTitle();
        std::string getScore();

        void setFont(sf::Font& font);
        void setTitleFont(sf::Font& font);
        void setScoreFont(sf::Font& font);

    protected:

    private:
        sf::Text title;
        sf::Text score;
};

#endif // SCORE_H
