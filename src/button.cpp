#include "button.h"
#include <SFML/Graphics.hpp>

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
  // Set up the rectangle shape
  m_rectShape.setPosition(position);
  m_rectShape.setSize(size);
  m_rectShape.setFillColor(color);
};

void Button::onClick(sf::Vector2f mousePos)
{
  if (m_rectShape.getGlobalBounds().contains(mousePos))
  {
    m_isClicked = true;
    if (m_clickAction != nullptr)
    {
      clickAction(mousePos);
    }
  }
}

void Button::setClickAction(void (*clickAction)(sf::Vector2f, Button&))
{
  m_clickAction = clickAction;
}

void Button::clickAction(sf::Vector2f mousePos)
{
  (*m_clickAction)(mousePos, *this);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(m_rectShape, states);
};
