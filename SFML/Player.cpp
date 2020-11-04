#include "Player.h"

void Player::initializeVariables()
{
	this->movementSpeed = 1.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

}

void Player::initializeTexture()
{
	//Load a texture
	if (this->texture.loadFromFile("Textures/mship1.png")==false)
	{
		printf("ERROR");
	}
}

void Player::initializeSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize sprite
	this->sprite.scale(0.05f, 0.05f);
}

Player::Player() {
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite();
}
Player::~Player() {

}
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}
const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax) {
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}
void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}
//Function
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
