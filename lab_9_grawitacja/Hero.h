#pragma once
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

class Hero
{
	sf::Clock clock;
	sf::Texture hero_texture;

	sf::Sprite hero_sp;
	sf::Event ev;
	int i = 3;
	int j = 0;
	float move_speed;
	std::vector<sf::IntRect> frames;
	std::vector<sf::IntRect> frames2;
	auto inittexture();
public:
	Hero();
	~Hero();

	void move(const float p_x, const float p_y);

	
	sf::FloatRect bounce();

	void breath();
	void intrect();
	void updateEvents();
	void render(sf::RenderTarget& target);
	void update();
	void setposition(sf::Vector2f pos);
	
};

