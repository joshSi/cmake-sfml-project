#include "button.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : m_position(position)
    , m_size(size)
    , m_color(color)
{
    // Set up the rectangle shape
    m_rectShape.setPosition(m_position);
    m_rectShape.setSize(m_size);
    m_rectShape.setFillColor(m_color);
};

void Button::onClick(sf::Vector2f mousePos)
{
    if (m_rectShape.getGlobalBounds().contains(mousePos))
    {
        m_isClicked = true;
        std::cout << "Button pressed!" << std::endl;
    }
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_rectShape, states);
};
