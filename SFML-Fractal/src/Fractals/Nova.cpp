#include "Nova.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Core/Global.h"

Nova::Nova()
{
}

Nova::~Nova()
{
}

void Nova::Init(const ResourceManager& resourceManager, sf::Vector2u windowSize)
{
	m_FractalShader.loadFromFile(Global::ExePath + "res/shaders/nova.glsl", sf::Shader::Fragment);
	Fractal::Init(resourceManager, windowSize);
}

void Nova::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	Fractal::UpdateAndRender(dt, target);

	std::string info = "Nova" + m_DebugInfo.getString();
	m_DebugInfo.setString(info);
	target.draw(m_DebugInfo);
}
