#pragma once
#include <SFML/Graphics/Font.hpp>

class ResourceManager
{
public:

	ResourceManager();
	~ResourceManager();

	void Init();
	const sf::Font& GetFont() const;

private:

	sf::Font m_Font;
};

