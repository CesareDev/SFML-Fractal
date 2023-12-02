#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(1280, 720), "Fractal", sf::Style::Default);
	win.setVerticalSyncEnabled(true);
	
	sf::Event ev;
	sf::Clock clock;

	Application app;
	app.Init(win.getSize());

	while (win.isOpen())
	{
		while (win.pollEvent(ev))
		{	
			if (ev.type == sf::Event::Closed)
				win.close();
			if (ev.type == sf::Event::KeyPressed)
				if (ev.key.code == sf::Keyboard::Escape)
					win.close();
		}

		float dt = clock.restart().asSeconds();

		win.clear();

		app.UpdateAndRender(dt, win);

		win.display();
	}

	return 0;
}