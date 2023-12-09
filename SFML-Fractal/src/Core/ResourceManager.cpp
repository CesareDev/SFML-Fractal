#include "ResourceManager.h"
#include "Core/Global.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::Init()
{
	m_Font.loadFromFile(Global::ExePath + "res/font/Pixeloid.ttf");
}

const sf::Font& ResourceManager::GetFont() const
{
	return m_Font;
}
