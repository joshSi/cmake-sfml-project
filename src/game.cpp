#include "game.h"
#include "button.h"
#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

int runGame(int framerate)
{
  sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "SFML Template");
  window.setFramerateLimit(framerate);

  Button button(sf::Vector2f(100, 100), sf::Vector2f(200, 50), sf::Color::Green);

  auto clickAction = [](sf::Vector2f mousePos, Button& button) {
    std::cout << "Button pressed!" << std::endl;
    if (button.m_rectShape.getFillColor() == sf::Color::Green)
    {
        button.m_rectShape.setFillColor(sf::Color::Blue);
    }
    else
    {
        button.m_rectShape.setFillColor(sf::Color::Green);
    }
  };

  button.setClickAction(clickAction);

  sf::Texture texture;
  if (!texture.loadFromFile("assets/cmake.png"))
  {
    // Error: Failed to load the texture
    return 1;
  }

  // Create a sprite using the texture
  sf::Sprite sprite(texture);
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
          window.close();
        }
        else if (event->is<sf::Event::MouseButtonPressed>())
        {
          button.onClick(sf::Vector2f(sf::Mouse::getPosition(window)));
        }

      window.clear();
      window.draw(sprite);
      window.draw(button);
      window.display();
    }
  }
  return 0;
}

