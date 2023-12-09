#include "Mandelbrot.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Core/Global.h"

Mandelbrot::Mandelbrot()
{
}

Mandelbrot::~Mandelbrot()
{
}

void Mandelbrot::Init(const ResourceManager& resourceManager, sf::Vector2u windowSize)
{
	m_FractalShader.loadFromFile(Global::ExePath + "res/shaders/mandelbrot.glsl", sf::Shader::Fragment);
	Fractal::Init(resourceManager, windowSize);
}

void Mandelbrot::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	Fractal::UpdateAndRender(dt, target);

	std::string info = "Mandelbrot" + m_DebugInfo.getString();
	m_DebugInfo.setString(info);
	target.draw(m_DebugInfo);
}
