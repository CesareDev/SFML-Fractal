#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

#include "Fractals/Fractal.h""

enum class FractalType
{
	MandelbrotSet,
	JuliaSet,
	Nova,
	BurningShip,
	Magnet,
	Count
};

class FractalManager
{
public:

	FractalManager();
	~FractalManager();

	void Init(const ResourceManager& resourceManager, sf::Vector2u windowSize);
	void UpdateAndRender(float dt, sf::RenderTarget& target);

private:

	void ChangeFractal();

private:

	sf::Vector2u m_WindowSize;
	std::unique_ptr<Fractal> m_CurrentFractal;
	FractalType m_CurrentFractalType;

	bool m_TabPressed = false;
	ResourceManager* m_ResourceManager;
};

