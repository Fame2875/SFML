#include "GAME.h"
//Private Function
void GAME::initializewindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Lighting Fighter",sf::Style::Close |sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}
void GAME::initializeTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/orange_bullet.png");
}
void GAME::initializePlayer()
{
	this->player = new Player();
	
}
void GAME::initializeEnemies()
{
	this->spawnTimerMax = 50.f;
		this->spawnTimer = this->spawnTimerMax;
}
void GAME::initializeWorld()
{
	this->worldBackgroundText.loadFromFile("Textures/background1.jpg");
	this->worldBackground.setTexture(this->worldBackgroundText);
}
void GAME::initializeSystem()
{
	this->points = 0;
}
void GAME::initializeGUI()
{
	//LOAD FRONT
	this->font.loadFromFile("fonts/Dosis-Light.ttf");
	//INIT point text
	this->pointText.setPosition(700, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::Cyan);
	this->pointText.setString("test");

	this->gameoverText.setFont(this->font);
	this->gameoverText.setCharacterSize(60);
	this->gameoverText.setFillColor(sf::Color::Red);
	this->gameoverText.setString("Game Over!");
	this->gameoverText.setPosition(
		this->window->getSize().x/2.f - this->gameoverText.getGlobalBounds().width / 2.f
		, this->window->getSize().y /2.f - this->gameoverText.getGlobalBounds().height / 2.f);
	//ทำเลือด
	this->playerHpbar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpbar.setFillColor(sf::Color::Red);
	this->playerHpbar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpbarback = this->playerHpbar;
	this->playerHpbarback.setFillColor(sf::Color(25, 25, 25, 200));

}
GAME::GAME()
{
	this->initializewindow();
	this->initializeTextures();
	this->initializeGUI();
	this->initializePlayer();
	this->initializeEnemies();
	this->initializeWorld();
	this->initializeSystem();
}
GAME::~GAME() {
	delete this->window;
	delete this->player;

	//Delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}
	//Delete Bullets
	for (auto& i : this->bullets) {
		delete i;
	}
	//Delete enemies
	for (auto& i : this->enemies) {
		delete i;
	}
}
//Function
void GAME::run()
{
	while (window->isOpen()) {

		this->updatePollEvents();
		if (this->player->getHp() > 0) 
			this->update();

		
		this->render();
	}
}

void GAME::updatePollEvents()
{

}

void GAME::updateInput()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed) this->window->close();
	}
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->player->move(-1.f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->player->move(1.f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->player->move(0.0f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->player->move(0.0f, 1.f);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPos().x + this->player->getBounds().width/2.f, this->player->getPos().y-20, 0.f, -1.f, /*speed bullet*/10.f));
	}
}

void GAME::updateWorld()
{
}

void GAME::updateCollision()
{
	//กันหลุดจอทางซ้าย
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setplayerPosition_OPT2(0.f,this->player->getBounds().top);
	}
	//ขวา
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setplayerPosition_OPT2(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	//บน
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setplayerPosition_OPT2(this->player->getBounds().left,0.f);
	}
	//ล่าง
	else if (this->player->getBounds().top + this->player->getBounds().height>= this->window->getSize().y)
	{
		this->player->setplayerPosition_OPT2( this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}

void GAME::updateBullet()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		//bullet culling(top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//delete bullet
			delete this->bullets.at(counter);;
			this->bullets.erase(this->bullets.begin() + counter);
			//--counter;
			std::cout << this->bullets.size() << "\n";
			//printf("%d\n",bullets.size());
		}
	
		++counter;
	}

}

void GAME::updateEnemies()
{
	//spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x-20.f, -100.f));
		this->spawnTimer = 0.f;
	}
	//update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();
		//bullet culling(top of screen)
		if (enemy->getBounds().top  >this->window->getSize().y)
		{
			//delete E
			delete this->enemies.at(counter);;
			this->enemies.erase(this->enemies.begin() + counter);
			//--counter;
			std::cout << this->bullets.size() << "\n";
			//printf("%d\n",bullets.size());
		}
		//ศัตรูหายตอนชนยาน
		else if (enemy->getBounds().intersects(this->player->getBounds())) 
		{
			player->loseHp(enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);;
			this->enemies.erase(this->enemies.begin() + counter);
			//--counter;
		}
		++counter;
	}

}

void GAME::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_delete = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_delete == false; k++) {
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				enemies[i]->loseHpEnemy(1);
				if (enemies[i]->getHpEnemy() == 0) {
					this->points += this->enemies[i]->getPoints();
					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);

					enemy_delete = true;
				}
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
			}
		}
	}

}

void GAME::updateGUI()
{
	std ::stringstream ss;
	ss << "Points: " <<this->points;
	this->pointText.setString(ss.str());

	//update player GUI
	hpPercent =static_cast<float>( this->player->getHp()) / this->player->getHpMax();
	this->playerHpbar.setSize(sf::Vector2f(300.f * hpPercent/*playerHpbar.getSize().x*/,playerHpbar.getSize().y));
}

void GAME::update()
{

	this->updateInput();

	this->player->update();

	this->updateCollision();

	this->updateBullet();

	this->updateEnemies();

	this->updateCombat();

	//this->renderGUI();

	this->updateGUI();

	this->updateWorld();
}

void GAME::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpbarback);
	this->window->draw(this->playerHpbar);
}

void GAME::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void GAME::render()
{
	this->window->clear();

	//วาดพื้นหลัง

	this->renderWorld();
	//Draw all the stuffs
	this->player->render(*this->window);
	for (auto* bullet : this->bullets) {
		bullet->render(this->window);
	}
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);

	}
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);

	}
	this->renderGUI();

	//GAME OVER
	if (this->player->getHp() <= 0) {
		this->window->draw(this->gameoverText);
	}
	this->window->display();
}
