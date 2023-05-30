#include "Game.h"

//private





auto Game::inithero()
{
	this->hero = new Hero;
	this->wall1 = new Walls;
	this->wall2 = new Walls;
	this->wall3 = new Walls;
	/*initial walls*/
}
void Game::initializeViriables()
{
	this->window = nullptr;
}
void Game::initializeWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "lab_9_psio");
	this->window->setFramerateLimit(90);
}
void Game::initializewall()
{
	this->wall1->initialize_Wall(sf::Vector2f(100, 300), sf::IntRect(41, 27, 94, 71));
	this->wall2->initialize_Wall(sf::Vector2f(400, 450), sf::IntRect(47, 123, 50, 36));
	this->wall3->initialize_Wall(sf::Vector2f(600, 400), sf::IntRect(41, 27, 94, 71));
	this->all_walls.emplace_back(*wall1);
	this->all_walls.emplace_back(*wall2);
	this->all_walls.emplace_back(*wall3);

}
void Game::initializetree()
{
	if (!this->texture_tree.loadFromFile("texture_pack/tileset.png")) {
		std::cerr << "Could not load texture" << std::endl;

	}

	this->tree.setTexture(this->texture_tree);
	this->tree.setPosition(605, 179);
	this->tree.scale(2.f, 2.f);

	this->tree.setTextureRect(sf::IntRect(192, 48, 128, 111));

}
void Game::initializebackgrond()
{

	if (!this->sky_texture.loadFromFile("texture_pack/sky.png"))
	{
		std::cerr << "Could not load texture" << std::endl;

	}

	this->sky.setTexture(this->sky_texture);

	this->sky.scale(8.f, 2.f);
	if (!this->background_texture.loadFromFile("texture_pack/clouds.png"))
	{
		std::cerr << "Could not load texture" << std::endl;

	}

	this->backgrond.setTexture(this->background_texture);
	
	this->backgrond.scale(4.f, 4.f);
	
}


Game::Game()
{
	fall = 0;
	this->initializeViriables();
	this->initializeWindow();
	this->inithero();
	this->initializewall();
	this->initializetree();
	this->initializebackgrond();

}
Game::~Game()
{
	delete this->window;
	delete this->hero;
	delete this->wall1;
	delete this->wall2;
	delete this->wall3;
}
const bool Game::running() const
{
	return this->window->isOpen();
}

//public



void Game::collision()
{
	if (grav)
	{
		fall = fall + 0.05;
		if (sf::Keyboard::W)
		{
			this->hero->move(0.f, -7 + fall);
		}
		
	}
	if (!grav)
	{
		fall = g;
	}
		sf::FloatRect playerbounds = hero->bounce();
		bool isColliding = false;
		for (auto& w : all_walls)
		{
			sf::FloatRect wallbounds = w.bounce();
			if (playerbounds.intersects(wallbounds))
			{
				sf::FloatRect overlap;
				playerbounds.intersects(wallbounds, overlap);
				this->hero->move(-overlap.width * std::signbit(overlap.left - playerbounds.left),
					-overlap.height * std::signbit(overlap.top - playerbounds.top));
				grav = false;
				std::cout << "kolizja" << std::endl;
				isColliding = true;
			}
		}
		if (!isColliding) {
			fall = fall + 0.03;
			this->hero->move(0.f, 1+fall);
		}
}
void Game::updateEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::W)
			{		
				grav = true;
			}
			break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->hero->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{	
		this->hero->move(1.f, 0.f);
	}
	if (sf::Event::TextEntered)
	{
		this->hero->breath();
	}	
	collision();
}
void Game::render()
{
	//visualasions renders the game obj
	this->window->clear();
	this->window->draw(sky);
	this->window->draw(backgrond);
	this->hero->render(*this->window);

	for (auto &w : all_walls)
	{
		w.render(*this->window);
	}
	this->window->draw(tree);
	this->window->display();
}
void Game::update()
{
	//there is game
	this->hero->updateEvents();
	this->updateEvents();
}


