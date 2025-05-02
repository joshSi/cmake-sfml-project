#ifndef CLICKABLE_H
#define CLICKABLE_H
#include <SFML/Graphics/Drawable.hpp>

class Clickable : public sf::Drawable
{
public:
    virtual void onClick(sf::Vector2f mousePos) = 0;
};

#endif