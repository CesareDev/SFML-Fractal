#pragma once
#include "Fractal.h"

class Julia : public Fractal
{
public:

	Julia();
	~Julia();

	// Inherited via Fractal
	void Init(const ResourceManager& resourceManager, sf::Vector2u windowSize) override;
	void UpdateAndRender(float dt, sf::RenderTarget& target) override;

private:

	sf::Vector2f m_MousePos;
};

