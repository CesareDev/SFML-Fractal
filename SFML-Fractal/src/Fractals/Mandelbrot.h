#pragma once
#include "Fractal.h"

class Mandelbrot : public Fractal
{
public:

	Mandelbrot();
	~Mandelbrot();

	// Inherited via Fractal
	void Init(const ResourceManager& resourceManager, sf::Vector2u windowSize) override;
	void UpdateAndRender(float dt, sf::RenderTarget& target) override;
};

