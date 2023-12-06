#pragma once
#include "Fractal.h"

class Magnet : public Fractal
{
public:

	Magnet();
	~Magnet();

	// Inherited via Fractal
	void Init(const ResourceManager& resourceManager, sf::Vector2u windowSize) override;
	void UpdateAndRender(float dt, sf::RenderTarget& target) override;
};

