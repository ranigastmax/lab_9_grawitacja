#pragma once
#include"Hero.h"
#include"Walls.h"
class Game
{
	//class that act as game engine
	sf::Texture texture_tree;
	sf::Texture background_texture;
	sf::Texture sky_texture;
	sf::Texture ground_texture;

	sf::Sprite tree; 
	sf::Sprite backgrond;
	sf::Sprite sky;
	sf::Sprite ground;
	//objects
	
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	Hero* hero;
	sf::Clock clock;
	sf::FloatRect next_pos;

	//walls
	sf::Vector2f position;
	sf::IntRect intrect;
	Walls* wall1;
	Walls* wall2;
	Walls* wall3;
	std::vector<Walls> all_walls;
	//end walls

	bool jump = false;
	bool grav = true;
	float fall;
	const float g = 1.f;

	auto inithero();
	void initializeViriables();
	void initializeWindow();
	void initializewall();
	void initializetree();
	void initializebackgrond();

public:

	Game();
	virtual ~Game();

	const bool running() const;
	void collision();
	void updateEvents();
	void render();
	void update();
	void falling();

};

