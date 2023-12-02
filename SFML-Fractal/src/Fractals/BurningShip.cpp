#include "BurningShip.h"

BurningShip::BurningShip()
{
}

BurningShip::~BurningShip()
{
}

void BurningShip::Init(sf::Vector2u windowSize)
{
	m_FractalShader.loadFromFile("res/shaders/burningship.glsl", sf::Shader::Fragment);
	Fractal::Init(windowSize);
}

void BurningShip::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	Fractal::UpdateAndRender(dt, target);

	std::string info = "Burning Ship" + m_DebugInfo.getString();
	m_DebugInfo.setString(info);
	target.draw(m_DebugInfo);
}
