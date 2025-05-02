#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "clickable.h"

class Button : public Clickable
{
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    virtual void onClick(sf::Vector2f mousePos);

private:
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    sf::Color m_color;
    sf::RectangleShape m_rectShape;

    bool m_isClicked;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
