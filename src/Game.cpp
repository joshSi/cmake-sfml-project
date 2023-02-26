#include "Game.h"
#include <SFML/Graphics.hpp>

int runGame(int framerate)
{
    auto window = sf::RenderWindow{ { 400u, 400u }, "CMakeSFMLProject" };
    window.setFramerateLimit(framerate);

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
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
