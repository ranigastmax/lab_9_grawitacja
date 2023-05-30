#include "Hero.h"





auto Hero::inittexture()
{
	if (!this->hero_texture.loadFromFile("texture_pack/Character.png")) {
		std::cerr << "Could not load texture" << std::endl;
		
	}
	
	this->hero_sp.setTexture(this->hero_texture);
	this->hero_sp.setPosition(100, 100);
	this->hero_sp.scale(2.f, 2.f);
   
	this->hero_sp.setTextureRect(sf::IntRect(14, 7, 18, 29));
	 
}
Hero::Hero()
{
	this->intrect();
	this->inittexture();
	this->move_speed = 2.f;
}
Hero::~Hero()
{
}
//MOVE---------------------------------------------
void Hero::move(const float p_x, const float p_y)
{
	this->hero_sp.move(this->move_speed * p_x, this->move_speed * p_y);
	
	
	
	if (i == 9) { i = 3; }
	if (clock.getElapsedTime().asSeconds() > 0.2)
	{
		if (p_x < 0)
		{
			if (hero_sp.getScale() == sf::Vector2f(2.f, 2.f))
			{
				this->hero_sp.setScale(-2.f, 2.f);
				this->hero_sp.setPosition(this->hero_sp.getPosition().x + this->hero_sp.getGlobalBounds().width, this->hero_sp.getPosition().y);
			}
			this->hero_sp.setTextureRect(frames[i]);
		}
		else if (p_x > 0)
		{
			if (hero_sp.getScale() == sf::Vector2f(-2.f, 2.f))
			{
				this->hero_sp.setScale(2.f, 2.f);
				this->hero_sp.setPosition(this->hero_sp.getPosition().x - this->hero_sp.getGlobalBounds().width, this->hero_sp.getPosition().y);
			}
			this->hero_sp.setTextureRect(frames[i]);
		}
		i += 1;
		clock.restart();
	}
}
void Hero::breath()
{
	if (j == 2) { j = 0; }
	if (clock.getElapsedTime().asSeconds() > 0.6)
	{
		this->hero_sp.setTextureRect(frames[j]);
	j = j + 1;
	clock.restart();
	}
}
void Hero::updateEvents()
{
	
	
}
void Hero::render(sf::RenderTarget& target)
{
	target.draw(this->hero_sp);
}
void Hero::update()
{

}
void Hero::setposition(sf::Vector2f pos)
{
	this->hero_sp.setPosition(pos);

}
void Hero::intrect()
{
	frames.emplace_back(sf::IntRect(14, 7, 18, 29));
	frames.emplace_back(sf::IntRect(66, 7, 21, 29));
	frames.emplace_back(sf::IntRect(115, 6, 21, 29));
	//---------------------------------------------------
	frames.emplace_back(sf::IntRect(167, 8, 21, 29));
	frames.emplace_back(sf::IntRect(216, 9, 21, 29));
	frames.emplace_back(sf::IntRect(266, 11, 21, 29));
	frames.emplace_back(sf::IntRect(317, 8, 21, 29));
	frames.emplace_back(sf::IntRect(367, 9, 21, 29));
	frames.emplace_back(sf::IntRect(416, 11, 21, 29));
	
}
sf::FloatRect Hero::bounce()
{
	return	this->hero_sp.getGlobalBounds();
}
