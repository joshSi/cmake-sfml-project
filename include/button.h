#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "clickable.h"

class Button : public Clickable
{
public:
  Button(sf::Vector2f position, sf::Vector2f size, sf::Color color);
  virtual void onClick(sf::Vector2f mousePos);
  void setClickAction(void (*clickAction)(sf::Vector2f, Button&));
  void clickAction(sf::Vector2f mousePos);

  sf::RectangleShape m_rectShape;

private:
  bool m_isClicked;
  void (*m_clickAction)(sf::Vector2f, Button&);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
