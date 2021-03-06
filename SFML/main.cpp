#include "stdafx.h"

void Update(float);
void Draw(sf::RenderWindow& window);

sf::Vector2i mouse_pos;

Player mario({ 0, 0 }, 50.f, 50.f);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Engine");
	window.setFramerateLimit(60);
	sf::Clock gameClock;
	float deltaTime = 1 / 60.f;

	while (window.isOpen())
	{
		mouse_pos = sf::Mouse::getPosition(window);

		float frameStart = gameClock.getElapsedTime().asSeconds();

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();

			if (e.type == sf::Event::MouseMoved)
			{
			}

			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Escape)
					window.close();
			}

			if (e.type == sf::Event::KeyReleased)
			{
				int a = sf::Keyboard::A;
				int d = sf::Keyboard::D;

				if (e.key.code == a || e.key.code == d)
					mario.m_slowDown = true;
			}
		}

		window.clear();

		Update(deltaTime);
		Draw(window);

		window.display();

		deltaTime = (gameClock.getElapsedTime().asSeconds() - frameStart) * 10;
	}
	return 0;
}

void Update(float deltaTime)
{
	mario.update(deltaTime);
}

void Draw(sf::RenderWindow& window)
{
	mario.draw(window);
}