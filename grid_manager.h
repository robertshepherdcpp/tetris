#pragma once

#include<SFML/Graphics.hpp>
#include<vector>

struct grid_manager
{
	grid_manager();

	auto handle_event(sf::Vector2f) -> void;

	std::vector<sf::Sprite> sprites{};

	sf::Texture copy_texture;
	sf::Sprite copy_sprite;
};