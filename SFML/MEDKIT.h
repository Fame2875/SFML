#ifndef MEDKIT_H
#define MEDKIT_H
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include "Player.h"
class MEDKIT
{
private:
	Player* player;
	float speed;
	int life;
	sf::Sprite Sprite_MEDKIT;
	sf::Texture Texture_MEDKIT;
	void initializeVariables();
	void initShape();
public:
	const int& getHeal() const;
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;


	void initialize_allMEDtexture();
	void initialize_allMEDSprite();
	MEDKIT(float pos_x, float pos_y);
	void update();
	void render(sf::RenderTarget* MEDKIT);
};
#endif //!MEDKIT_H

