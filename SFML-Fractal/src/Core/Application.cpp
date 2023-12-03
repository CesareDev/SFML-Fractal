#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::Init(sf::Vector2u windowSize)
{
	m_WindowSize = windowSize;
	m_ResourceManager.Init();
	m_FractalManager.Init(m_ResourceManager, m_WindowSize);

	m_FPS.setFont(m_ResourceManager.GetFont());
	m_FPS.setCharacterSize(15);
	m_FPS.setPosition(4.f, 4.f);
	m_FPS.setFillColor(sf::Color::Black);
}

void Application::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	m_FractalManager.UpdateAndRender(dt, target);

	int FPS = 1 / dt;
	m_FPS.setString(std::to_string(FPS));
	m_FPS.setPosition(m_WindowSize.x - m_FPS.getGlobalBounds().width - 4.f, 4.f);
	target.draw(m_FPS);
}
