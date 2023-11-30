#include "FractalManager.h"
#include <SFML/Window/Keyboard.hpp>

#include "Mandelbrot.h"
#include "Julia.h"

FractalManager::FractalManager()
{
}

FractalManager::~FractalManager()
{
}

void FractalManager::Init(sf::Vector2u windowSize)
{
	m_WindowSize = windowSize;
	m_CurrentFractalType = FractalType::MandelbrotSet;
	m_CurrentFractal.reset(new Mandelbrot());
	m_CurrentFractal->Init(m_WindowSize);
}

void FractalManager::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	ChangeFractal();
	
	m_CurrentFractal->HandleCamera(dt);
	m_CurrentFractal->HandleZoom(dt);
	m_CurrentFractal->UpdateAndRender(dt, target);
}

void FractalManager::ChangeFractal()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && !m_TabPressed)
	{
		m_TabPressed = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && m_TabPressed)
	{
		m_TabPressed = false;
		int nextType = (int)m_CurrentFractalType + 1;

		if ((FractalType)nextType == FractalType::Count)
			m_CurrentFractalType = (FractalType)0;
		else
			m_CurrentFractalType = (FractalType)((int)m_CurrentFractalType + 1);

		switch (m_CurrentFractalType)
		{
		case FractalType::MandelbrotSet:
			m_CurrentFractal.reset(new Mandelbrot());
			break;
		case FractalType::JuliaSet:
			m_CurrentFractal.reset(new Julia());
			break;
		case FractalType::Count:
			break;
		default:
			break;
		}
		m_CurrentFractal->Init(m_WindowSize);
	}
}
