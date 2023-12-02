#include "Mandelbrot.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

Mandelbrot::Mandelbrot()
{
}

Mandelbrot::~Mandelbrot()
{
}

void Mandelbrot::Init(sf::Vector2u windowSize)
{
	m_FractalShader.loadFromFile("res/shaders/mandelbrot.glsl", sf::Shader::Fragment);
	Fractal::Init(windowSize);
}

void Mandelbrot::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	Fractal::UpdateAndRender(dt, target);

	std::string info = "Mandelbrot" + m_DebugInfo.getString();
	m_DebugInfo.setString(info);
	target.draw(m_DebugInfo);
}
