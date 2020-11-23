#include "Player.h"

void Player::initializeVariables()
{
	this->movementSpeed = 5.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	hpMax_ship = 50;
	hp_ship = hpMax_ship;
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
	//player pos
	this->sprite.setPosition(395,750);
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
const sf::FloatRect Player::getBounds() const
{

	return this->sprite.getGlobalBounds();
}
const int& Player::getHp() const
{
	return hp_ship;
}
const int& Player::getHpMax() const
{
	return hpMax_ship;
}
void Player::setplayerPosition_OPT1(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}
void Player::setplayerPosition_OPT2(const float x, const float y)
{
	this->sprite.setPosition(x,y);
}
void Player::setHp(const int hp)
{
	this->hp_ship = hp;
}
void Player::loseHp(const int value)
{
	this->hp_ship -= value;
	if (this->hp_ship < 0)
	{
		this->hp_ship = 0;
	}
	printf("%d\n", hp_ship);
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
