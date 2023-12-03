#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include "ResourceManager.h"
#include "FractalManager.h"

class Application
{
public:

	Application();
	~Application();

	void Init(sf::Vector2u windowSize);
	void UpdateAndRender(float dt, sf::RenderTarget& target);

private:

	sf::Vector2u m_WindowSize;
	ResourceManager m_ResourceManager;
	FractalManager m_FractalManager;

	sf::Text m_FPS;
};

