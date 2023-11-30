#include <SFML/Graphics.hpp>
#include "FractalManager.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(1280, 720), "Fractal", sf::Style::Default);
	win.setVerticalSyncEnabled(true);

	sf::Event ev;
	sf::Clock clock;

	FractalManager m_Manager;
	m_Manager.Init(win.getSize());

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

		m_Manager.UpdateAndRender(dt, win);

		win.display();
	}

	return 0;
}