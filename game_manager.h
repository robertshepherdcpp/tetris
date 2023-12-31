#pragma once

#include<SFML/Graphics.hpp>

#include<chrono>

using namespace std::chrono_literals;

struct game_manager
{
	game_manager();

	auto rotate_clockwise() -> void;
	auto rotate_anticlockwise() -> void;
	auto move_down_one() -> void;
	auto random_number() -> int;
	auto print(sf::RenderWindow& window) -> void;
	auto update() -> void;

	sf::Texture three_pronged_t;
	sf::Sprite three_pronged_s;
	
	sf::Texture l_shaped_t;
	sf::Sprite l_shaped_s;

	sf::Texture horizontal_line_t;
	sf::Sprite horizontal_line_s;

	sf::Texture s_shape_t;
	sf::Sprite s_shape_s;

	sf::Sprite current_sprite = three_pronged_s;

	std::chrono::system_clock::time_point last_time_checked = std::chrono::system_clock::now();
};