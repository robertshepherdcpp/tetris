#include "game_manager.h"

game_manager::game_manager()
{
	three_pronged_t.loadFromFile("three_pronged.png");
	three_pronged_s.setTexture(three_pronged_t);
	l_shaped_t.loadFromFile("l_shape.png");
	l_shaped_s.setTexture(l_shaped_t);
	horizontal_line_t.loadFromFile("horizontal_line.png");
	horizontal_line_s.setTexture(horizontal_line_t);
	s_shape_t.loadFromFile("s_shape.png");
	s_shape_s.setTexture(s_shape_t);

	current_sprite = horizontal_line_s;
	current_sprite.setPosition(sf::Vector2f(100, 0));
}

auto game_manager::rotate_clockwise() -> void
{
	current_sprite.setRotation(current_sprite.getRotation() + 90);
}

auto game_manager::rotate_anticlockwise() -> void
{
	current_sprite.setRotation(current_sprite.getRotation() - 90);
}

auto game_manager::move_down_one() -> void
{
	current_sprite.setPosition(sf::Vector2f(current_sprite.getPosition().x, current_sprite.getPosition().y - 20));
	if (current_sprite.getPosition().y < 0)
	{
		// we have finished with this one and we are going to go onto the next one
		auto num = random_number();
		if (num == 1)
		{
			current_sprite = three_pronged_s;
			current_sprite.setPosition(sf::Vector2f(100, 0));
		}
		else if (num == 2)
		{
			current_sprite = l_shaped_s;
			current_sprite.setPosition(sf::Vector2f(100, 0));
		}
		else if (num == 3)
		{
			current_sprite = horizontal_line_s;
			current_sprite.setPosition(sf::Vector2f(100, 0));
		}
		else if (num == 4)
		{
			current_sprite = s_shape_s;
			current_sprite.setPosition(sf::Vector2f(100, 0));
		}
	}
}

auto game_manager::random_number() -> int
{
	// TODO: actually return a random number;
	return 2;
}

auto game_manager::print(sf::RenderWindow& window) -> void
{
	window.draw(current_sprite);
}
