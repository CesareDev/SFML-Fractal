#include <SFML/Graphics.hpp>
#include "FractalManager.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(1280, 720), "Fractal", sf::Style::Default);
	win.setVerticalSyncEnabled(true);

	sf::Event ev;
	sf::Clock clock;

	sf::Text t;
	sf::Font f; 
	f.loadFromFile("res/font/PixeloidMono-d94EV.ttf");
	
	t.setFont(f);
	t.setCharacterSize(15);
	t.setString("FPS: ");

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

		int fps = 1.f / dt;
		std::string s = "FPS: " + std::to_string(fps);
		t.setString(s);
		t.setPosition(win.getSize().x - t.getGlobalBounds().width - 4.f, 4.f);

		win.clear();

		m_Manager.UpdateAndRender(dt, win);

		win.draw(t);

		win.display();
	}

	return 0;
}