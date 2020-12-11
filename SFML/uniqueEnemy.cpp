#include "uniqueEnemy.h"

#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
void uniqueEnemy::initializeVariables()
{
	//type = rand() % 3;
	hp = 20;
	speed =0;
	hpMax = 20 ;
	damage = 10;
	points = 20;
	/*uniquemoveTimer = 0.f;
	uniquemoveTimer = 100.f;
	uniquemovebackTimer = 0.f;
	uniquemovebackTimerMax = 100.f;*/
}
void uniqueEnemy::initialize_allenemytexture()
{
	this->enemy_uniqueship_1.loadFromFile("Textures/ENEMY_1.png");
	this->enemy_uniqueship_2.loadFromFile("Textures/ENEMY_2.png");
	this->enemy_uniqueship_3.loadFromFile("Textures/ENEMY_3.png");
}

void uniqueEnemy::initialize_allenemySprite()
{
	// Set the texture to the sprite
		this->Sprite_enemy_uniqueship_1.setTexture(this->enemy_uniqueship_1);

	//Resize sprite
	this->Sprite_enemy_uniqueship_1.scale(0.2f, 0.2f);
	// Set the texture to the sprite
		this->Sprite_enemy_uniqueship_2.setTexture(this->enemy_uniqueship_2);

	//Resize sprite
	this->Sprite_enemy_uniqueship_2.scale(0.3f, 0.3f);

	// Set the texture to the sprite
	this->Sprite_enemy_uniqueship_3.setTexture(this->enemy_uniqueship_3);

	//Resize sprite
	this->Sprite_enemy_uniqueship_3.scale(0.5f, 0.5f);

}
void uniqueEnemy::initShape()
{
}


uniqueEnemy::uniqueEnemy(float pos_x,float pos_y)
{
	this->initializeVariables();
	this->initialize_allenemytexture();
	this->initialize_allenemySprite();
	this->initShape();

	this->Sprite_enemy_uniqueship_1.setPosition(pos_x,pos_y);
	this->Sprite_enemy_uniqueship_2.setPosition(pos_x, pos_y);
	this->Sprite_enemy_uniqueship_3.setPosition(pos_x, pos_y);
}

uniqueEnemy::~uniqueEnemy()
{

}
const int& uniqueEnemy::getDamage() const
{
	return this->damage;
}
const sf::Vector2f& uniqueEnemy::getPos() const
{
	return this->Sprite_enemy_uniqueship_1.getPosition();
}
const sf::FloatRect uniqueEnemy::getBounds() const
{

	return this->Sprite_enemy_uniqueship_1.getGlobalBounds();
}

const int& uniqueEnemy::getType() const
{
	return this->type;
}
void uniqueEnemy::movinguniqueEnemy(float pos_x, float pos_y)
{
	this->Sprite_enemy_uniqueship_1.move(pos_x, pos_y);
}
//Functions
void uniqueEnemy::update()
{
	this->Sprite_enemy_uniqueship_1.move(0, 20.f);
	/*if (this->uniquemoveTimer <= this->uniquemoveTimerMax)
	{
		this->Sprite_enemy_uniqueship_1.move(2.f, 0.f);
		this->uniquemoveTimer += 0.5;
		uniquemovebackTimer = 0;
	}*/
	/*if (this->uniquemoveTimer >= this->uniquemoveTimerMax)
	{
		this->Sprite_enemy_uniqueship_1.move(-2.f, 0.f);
		this->uniquemovebackTimer += 0.5;
		if (this->uniquemovebackTimer >= this->uniquemovebackTimerMax) {
			uniquemovebackTimer = 0;
			uniquemoveTimer = 0;
		}
	}*/
	
}

void uniqueEnemy::render(sf::RenderTarget* uniquetarget/*, int type*/)
{
	uniquetarget->draw(this->Sprite_enemy_uniqueship_1);
	/*this->type = type;*/
	/*switch (this->type)
	{
	case NUM1SHIP:
		uniquetarget->draw(this->Sprite_enemy_uniqueship_1);
		break;
	case NUM2SHIP:
		uniquetarget->draw(this->Sprite_enemy_uniqueship_2);
		break;
	case NUM3SHIP:
		uniquetarget->draw(this->Sprite_enemy_uniqueship_3);
		break;
	}*/
}
