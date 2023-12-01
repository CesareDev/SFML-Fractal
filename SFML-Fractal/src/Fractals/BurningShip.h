#pragma once
#include "Fractal.h"

class BurningShip : public Fractal
{
public:

	BurningShip();
	~BurningShip();

	// Inherited via Fractal
	void Init(sf::Vector2u windowSize) override;
	void UpdateAndRender(float dt, sf::RenderTarget& target) override;
};

