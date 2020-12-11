#include "ENEMYBULLET.h"

ENEMYBULLET::ENEMYBULLET()
{
}

ENEMYBULLET::ENEMYBULLET(sf::Texture* texture, float pos_x, float posy, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, posy);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

ENEMYBULLET::~ENEMYBULLET()
{

}

const sf::FloatRect ENEMYBULLET::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void ENEMYBULLET::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void ENEMYBULLET::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
