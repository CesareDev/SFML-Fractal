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
	m_FractalManager.Init(m_WindowSize);
}

void Application::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	m_FractalManager.UpdateAndRender(dt, target);
}
