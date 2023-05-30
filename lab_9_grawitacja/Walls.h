#pragma once
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
class Walls
{
	sf::Texture wall_texture;
	sf::Sprite wall;



public:
	Walls();
	~Walls();

	void initialize_Wall(sf::Vector2f, sf::IntRect );
	void render(sf::RenderTarget& target);
	void update();
	sf::FloatRect bounce();
};

