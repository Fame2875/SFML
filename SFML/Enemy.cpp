#include "Enemy.h"



void Enemy::initializeVariables()
{
	this->pointCount = rand() % 8 + 3; //3-10
	type = 0;
	speed = static_cast<float>(this->pointCount/3);
	 hp	= this->hpMax;
	 hpMax = static_cast<int>(this->pointCount);;
	 damage = this->pointCount;
	 points = this->pointCount;
}

void Enemy::initShape()
{
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initializeVariables();
	this->shape.setPosition(pos_x, pos_y);
	this->initShape();
	
}

Enemy::~Enemy()
{

}
const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}
const int& Enemy::getPoints() const
{
	return this->points;
}
const int& Enemy::getDamage() const
{
	return this->damage;
}
const int& Enemy::getHpEnemy() const
{
	return hp;
}
void Enemy::loseHpEnemy(const int value)
{
	this->hp -= value;
	printf("en = %d", hp);
}
//Function
void Enemy::update()
{
	this->shape.move(0.f, /*ความเร็วอุกกาบาต*/speed);

}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);

}
