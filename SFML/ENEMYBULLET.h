
#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <SFML/Graphics.hpp>
#include<stdio.h>
class ENEMYBULLET
{
private:

	sf::Sprite shape;
	sf::Vector2f direction;
	float movementSpeed;
public:
	ENEMYBULLET();
	ENEMYBULLET(sf::Texture* texture, float pos_x, float posy, float dir_x, float dir_y, float movement_speed);
	virtual ~ENEMYBULLET();

	//Accessor
	const sf::FloatRect getBounds() const;
	void update();
	void render(sf::RenderTarget* target);
};
#endif // !ENEMYBULLET_H

