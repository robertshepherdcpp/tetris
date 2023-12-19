#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include "grid_manager.h"

grid_manager::grid_manager()
{
	copy_texture.loadFromFile("grid_box.png");
	copy_sprite.setTexture(copy_texture);

	for (int i = 0; i < 200; (i += copy_sprite.getGlobalBounds().height()))
	{
		for (int j = 0; j < 200; (j += copy_sprite.getGlobalBounds().width()))
		{
			sf::Sprite other_sprite = copy_sprite;
			other_sprite.setPosition(j, i);
			sprites.push_back(other_sprite);
		}
	}
}

auto grid_manager::handle_event(sf::Vector2f e) -> void
{
	auto posInList = 0;
	auto mousePos = e;
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i].getGlobalBounds().contains(e))
		{
			posInList = i;
		}
	}
	std::cout << "You pressed position " << posInList << ".\n";
}

