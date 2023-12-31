#include "BurningShip.h"
#include "Core/Global.h"

BurningShip::BurningShip()
{
}

BurningShip::~BurningShip()
{
}

void BurningShip::Init(const ResourceManager& resourceManager, sf::Vector2u windowSize)
{
	m_FractalShader.loadFromFile(Global::ExePath + "res/shaders/burningship.glsl", sf::Shader::Fragment);
	Fractal::Init(resourceManager, windowSize);
}

void BurningShip::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	Fractal::UpdateAndRender(dt, target);

	std::string info = "Burning Ship" + m_DebugInfo.getString();
	m_DebugInfo.setString(info);
	target.draw(m_DebugInfo);
}
