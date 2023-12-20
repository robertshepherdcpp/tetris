#include <SFML/Window.hpp>

// #include"grid_manager.h"
#include"game_manager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "My window");
    // grid_manager g{}; commented out because it currently has errors
    game_manager g{};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                //auto pos = sf::Mouse::getPosition();
                //g.handle_event(sf::Vector2f(pos.x, pos.y));
                if (event.key.code == sf::Keyboard::A)
                {
                    g.rotate_anticlockwise();
                }
                else if (event.key.code == sf::Keyboard::W)
                {
                    g.rotate_clockwise();
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    g.move_down_one();
                }
            }
        }
        g.print(window);
    }
    return 0;
}