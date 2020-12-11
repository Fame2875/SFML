﻿#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
class Enemy
{
private:
	unsigned pointCount;
	sf::CircleShape shape;
	
	int type;
	int hp;
	float speed;
	int hpMax;
	int damage;
	int points;
	void initializeVariables();
	void initShape();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();
	//Accessor เครื่องมือ
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;
	const int& getHpEnemy() const;
	//function
	void loseHpEnemy(const int value);
	
	void update();
	void render(sf::RenderTarget* target);
};
#endif //!ENEMY_H
