#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "clickable.h"
#include <functional>

class Button : public Clickable
{
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    virtual void onClick(sf::Vector2f mousePos);
    void setClickAction(std::function<void(sf::Vector2f, Button&)> clickAction);
    void clickAction(sf::Vector2f mousePos);

    sf::RectangleShape m_rectShape;

private:
    bool m_isClicked;
    std::function<void(sf::Vector2f, Button&)> m_clickAction;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
