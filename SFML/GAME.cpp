#include "GAME.h"
//Private Function
void GAME::initializewindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600, 800), "Lighting Fighter",sf::Style::Close |sf::Style::Titlebar);
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
GAME::GAME()
{
	this->initializewindow();
	this->initializeTextures();
	this->initializePlayer();
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
}
//Function
void GAME::run()
{
	while (window->isOpen()) {
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
		this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPos().x +38, this->player->getPos().y-20, 0.f, -1.f, 3.f));
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
			--counter;
			std::cout << this->bullets.size() << "\n";
			//printf("%d\n",bullets.size());
		}
	
		++counter;
	}

}

void GAME::update()
{
	this->updatePollEvents();
	this->updateInput();

	this->player->update();
	this->updateBullet();
}

void GAME::render()
{
	this->window->clear();

	//Draw all the stuffs
	this->player->render(*this->window);
	for (auto* bullet : this->bullets) {
		bullet->render(this->window);
	}
	this->window->display();
}
