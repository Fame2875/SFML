#ifndef uniqueEnemy_H
#define uniqueEnemy_H
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include "Player.h"
/*enum uniqueEnemytype
{
	NUM1SHIP = 0,
	NUM2SHIP,
	NUM3SHIP,
	NROFTYPE
};*/
class uniqueEnemy
{
private:

	Player* player;
	int type;
	int hp;
	float speed;
	int hpMax;
	int damage;
	int points;
	float uniquemoveTimer;
	float uniquemoveTimerMax;
	float uniquemovebackTimer;
	float uniquemovebackTimerMax;
	sf::Sprite Sprite_enemy_uniqueship_3;
	sf::Sprite Sprite_enemy_uniqueship_1;
	sf::Sprite Sprite_enemy_uniqueship_2;
	sf::Texture enemy_uniqueship_1;
	sf::Texture enemy_uniqueship_2;
	sf::Texture enemy_uniqueship_3;
	void initializeVariables();
	void initShape();
public:

	void initialize_allenemytexture();
	void initialize_allenemySprite();
	uniqueEnemy(float pos_x, float pos_y);
	virtual ~uniqueEnemy();
	const int& getDamage() const;
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	//Accessor
	const int& getType() const;
	//Functions
	void movinguniqueEnemy(float pos_x, float pos_y);
	void update();
	void render(sf::RenderTarget* uniquetarget/*,int type*/);
};

#endif //!uniqueEnemy_H