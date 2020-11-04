#include<map>
#include "Player.h"
#include"Bullet.h"
class GAME
{
private:
	//window
	sf::RenderWindow* window;
	//Resorces
	std::map<std::string, sf::Texture*>textures;
	std::vector<Bullet*> bullets;
	//player
	Player* player;

	//PrivateFunction
	void initializewindow();
	void initializeTextures();
	void initializePlayer();
public:
	//Function
	void run();

	void updatePollEvents();
	void updateInput();
	void updateBullet();
	void update();
	void render();
public:
	GAME();
	virtual ~GAME();
};
