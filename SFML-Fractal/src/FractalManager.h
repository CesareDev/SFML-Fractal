#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

#include "Fractals/Fractal.h"

enum class FractalType
{
	MandelbrotSet,
	JuliaSet,
	Nova,
	BurningShip,
	Count
};

class FractalManager
{
public:

	FractalManager();
	~FractalManager();

	void Init(sf::Vector2u windowSize);
	void UpdateAndRender(float dt, sf::RenderTarget& target);

private:

	void ChangeFractal();

private:

	std::unique_ptr<Fractal> m_CurrentFractal;
	FractalType m_CurrentFractalType;
	sf::Vector2u m_WindowSize;

	bool m_TabPressed = false;

	sf::Font m_Font;
	sf::Text m_DebugInfo;
};

