#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::Init()
{
	m_Font.loadFromFile("res/font/Pixeloid.ttf");
}

const sf::Font& ResourceManager::GetFont() const
{
	return m_Font;
}
