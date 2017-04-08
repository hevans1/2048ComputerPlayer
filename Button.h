#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cassert>
#include <functional>

class Button : public sf::Drawable
{
    public:
        Button();
        virtual ~Button();

        void initialize(const sf::Vector2f& size, const sf::Vector2f& position, std::function<void()> action_in);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        bool contains(const int& x, const int& y);

        void react(sf::Event& event);

        void setAction(std::function<void()>& action_in);

        void setFont(sf::Font& font);

    protected:

    private:
        sf::RectangleShape button;
        sf::Text text;

        std::function<void()> action;
};

#endif // BUTTON_H
