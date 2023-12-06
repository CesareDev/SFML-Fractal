#include "Magnet.h"

Magnet::Magnet()
{
}

Magnet::~Magnet()
{
}

void Magnet::Init(const ResourceManager& resourceManager, sf::Vector2u windowSize)
{
	m_FractalShader.loadFromFile("res/shaders/magnet.glsl", sf::Shader::Fragment);
	Fractal::Init(resourceManager, windowSize);
}

void Magnet::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	Fractal::UpdateAndRender(dt, target);

	std::string info = "Magnet" + m_DebugInfo.getString();
	m_DebugInfo.setString(info);
	target.draw(m_DebugInfo);
}
