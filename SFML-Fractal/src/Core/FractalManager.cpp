#include "FractalManager.h"
#include <SFML/Window/Keyboard.hpp>

#include "Fractals/Mandelbrot.h"
#include "Fractals/Julia.h"
#include "Fractals/Nova.h"
#include "Fractals/BurningShip.h"
#include "Fractals/Magnet.h"

FractalManager::FractalManager()
{
}

FractalManager::~FractalManager()
{
}

void FractalManager::Init(const ResourceManager& resourceManager, sf::Vector2u windowSize)
{
	m_WindowSize = windowSize;
	m_ResourceManager = const_cast<ResourceManager*>(& resourceManager);
	m_CurrentFractalType = FractalType::MandelbrotSet;
	m_CurrentFractal.reset(new Mandelbrot());
	m_CurrentFractal->Init(*m_ResourceManager, m_WindowSize);
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
		case FractalType::Nova:
			m_CurrentFractal.reset(new Nova());
			break;
		case FractalType::BurningShip:
			m_CurrentFractal.reset(new BurningShip());
			break;
		case FractalType::Magnet:
			m_CurrentFractal.reset(new Magnet());
			break;
		case FractalType::Count:
			break;
		default:
			break;
		}
		m_CurrentFractal->Init(*m_ResourceManager, m_WindowSize);
	}
}
