#include "Button.h"

Button::Button()
{
    //ctor
}

Button::~Button()
{
    //dtor
}

void Button::initialize(const sf::Vector2f& size, const sf::Vector2f& position, std::function<void()> action_in)
{
    button.setSize(size);
    button.setPosition(position);
    this->setAction(action_in);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(button, states);
    target.draw(text, states);
}

void Button::react(sf::Event& event)
{
    assert(event.type == event.MouseButtonReleased);
    int x = event.mouseButton.x, y = event.mouseButton.y;
    if (this->contains(x,y))
    {
        action();
    }
}

bool Button::contains(const int& x, const int& y)
{
    return button.getGlobalBounds().contains(x, y);
}

void Button::setAction(std::function<void()>& action_in)
{
    action = action_in;
}

void Button::setFont(sf::Font& font)
{
    text.setFont(font);
}
