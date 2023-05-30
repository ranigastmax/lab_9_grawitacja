#include "Walls.h"

void Walls::initialize_Wall(sf::Vector2f position, sf::IntRect intrect)
{
	if (!this->wall_texture.loadFromFile("texture_pack/tileset.png")) {
		std::cerr << "Could not load texture" << std::endl;

	}
	this->wall.setTexture(this->wall_texture);
	this->wall.setTextureRect(intrect);
	this->wall.setPosition(position);
	this->wall.scale(2.f, 2.f);
}

Walls::Walls()
{
	
}

Walls::~Walls()
{
	
}

void Walls::render(sf::RenderTarget& target)
{
	target.draw(this->wall);
}

void Walls::update()
{
}

sf::FloatRect Walls::bounce()
{

	return this->wall.getGlobalBounds();
}
