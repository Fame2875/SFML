#include "MEDKIT.h"

void MEDKIT::initializeVariables()
{
	speed = 0;
		life = 10;
}

void MEDKIT::initShape()
{
}

const int& MEDKIT::getHeal() const
{
	return this->life;
}

const sf::Vector2f& MEDKIT::getPos() const
{
	return this->Sprite_MEDKIT.getPosition();
}

const sf::FloatRect MEDKIT::getBounds() const
{
	return this->Sprite_MEDKIT.getGlobalBounds();
}

void MEDKIT::initialize_allMEDtexture()
{
	this->Texture_MEDKIT.loadFromFile("Textures/MEDKIT.png");
}

void MEDKIT::initialize_allMEDSprite()
{
	this->Sprite_MEDKIT.setTexture(this->Texture_MEDKIT);
	this->Sprite_MEDKIT.scale(.2f, .2f);
}

MEDKIT::MEDKIT(float pos_x, float pos_y)
{
	this->initializeVariables();
	this->initialize_allMEDtexture();
	this->initialize_allMEDSprite();
	this->Sprite_MEDKIT.setPosition(pos_x, pos_y);
}

void MEDKIT::update()
{
	this->Sprite_MEDKIT.move(0, 3.f);
}

void MEDKIT::render(sf::RenderTarget* MEDKITTRAGET)
{
	MEDKITTRAGET->draw(this->Sprite_MEDKIT);
}




