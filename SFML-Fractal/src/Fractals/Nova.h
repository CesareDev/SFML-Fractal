#pragma once
#include "Fractal.h"

class Nova : public Fractal
{
public:

	Nova();
	~Nova();

	// Inherited via Fractal
	void Init(const ResourceManager& resourceManager, sf::Vector2u windowSize) override;
	void UpdateAndRender(float dt, sf::RenderTarget& target) override;
};

