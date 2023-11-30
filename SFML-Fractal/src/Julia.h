#pragma once
#include "Fractal.h"

class Julia : public Fractal
{
public:

	Julia();
	~Julia();

	void Init(sf::Vector2u windowSize) override;
	void UpdateAndRender(float dt, sf::RenderTarget& target) override;
	void ResetVariables() override;

private:

	sf::Vector2f m_MousePos;
};

