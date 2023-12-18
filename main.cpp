#include <SFML/Window.hpp>

#include"grid_manager.h"

int main()
{
    sf::Window window(sf::VideoMode(200, 200), "My window");
    grid_manager g{};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                auto pos = sf::Mouse::getPosition();
                g.handle_event(sf::Vector2f(pos.x, pos.y));
            }
        }
    }
    return 0;
}