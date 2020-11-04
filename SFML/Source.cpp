
#include"GAME.h"
int main() {
	GAME GAME;
	GAME.run();
	//end app
	return 0;
}

















/*int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 1000), "GG");//เปิดหน้าจอ,ขนาดจอ,ชื่อ
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	//player.setFillColor(sf::Color::Red);
	player.setPosition(.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("mship1.png");
	player.setTexture(&playerTexture);
	//sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f,512.0f));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//ปิดหน้าจอ
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		}
		window.clear(sf::Color(150,150,150));
		window.draw(player);
		//window.setView(view);
		window.display();
	}
	return 0;
}*/