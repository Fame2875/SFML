#include<map>
#include<string>
#include<sstream>
#include "Player.h"
#include"Bullet.h"
#include "Enemy.h"
#include "uniqueEnemy.h"
#include "ENEMYBULLET.h"
#include "Player.h"
#include "MEDKIT.h"
class GAME
{
private:
	//window
	sf::RenderWindow* window;
	//Resorces
	std::map<std::string, sf::Texture*>textures;
	std::vector<Bullet*> bullets;

	std::map<std::string, sf::Texture*>enemytextures;
	std::vector<ENEMYBULLET*> enemybullet;

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text gameoverText;
	//พื้นหลัง
	sf::Texture worldBackgroundText;
	sf::Sprite worldBackground;
	//system
	unsigned points;
	//player
	Player* player;

	//playerGUI
	sf::RectangleShape playerHpbar;
	sf::RectangleShape playerHpbarback;

	//ENEMY
	float uniquespawnTimer;
	float uniquespawnTimerMax;
	
	std::vector<uniqueEnemy*> uniqueenemies;

	std::vector<MEDKIT*> medkit;
	bool MEDSPAWN = false;
	//uniqueEnemy* uniqueenemy;
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	float hpPercent;
	unsigned Enemytype;
//PrivateFunction
	void initializewindow();
	void initializeTextures();
	void initializePlayer();
	void initializeEnemies();
	void initializeuniqueEnemy();
	void initializeMEDKIT();
	void initializeWorld();
	void initializeSystem();
	
public:
	//Function
	void initializeGUI();
	void run();
	void updatePollEvents();
	void updateInput();
	void updateWorld();
	void updateCollision();
	void updateBullet();
	void updateenemyBullet();
	void updateEnemies();
	void updateuniqueEnemy();
	void updateMEDKIT();
	void updateCombat();
	void updateGUI();
	void update();
	void renderGUI();
	void renderWorld();
	void render();
public:
	GAME();
	virtual ~GAME();
};
