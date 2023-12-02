#include "Julia.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Julia::Julia()
{
}

Julia::~Julia()
{
}

void Julia::Init(sf::Vector2u windowSize)
{
	m_FractalShader.loadFromFile("res/shaders/julia.glsl", sf::Shader::Fragment);
	Fractal::Init(windowSize);
}

void Julia::UpdateAndRender(float dt, sf::RenderTarget& target)
{	
	Fractal::UpdateAndRender(dt, target);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_MousePos = sf::Vector2f(sf::Mouse::getPosition((sf::RenderWindow&)target));
		m_FractalShader.setUniform("u_MousePosition", m_MousePos);
	}

	float ratio = m_WindowSize.x / (float)m_WindowSize.y;
	float imgStartParam = -1.f;
	float imgEndParam = 1.f;
	float realStartParam = imgStartParam * ratio;
	float realEndParam = imgEndParam * ratio;
	sf::Vector2f mpos = sf::Vector2f(m_MousePos.x, m_WindowSize.y - m_MousePos.y);

	sf::Vector2f c =
	{
		realStartParam + (mpos.x / m_WindowSize.x) * (realEndParam - realStartParam),
		imgStartParam + (mpos.y / m_WindowSize.y) * (imgEndParam - imgStartParam)
	};

	bool neg = false;
	if (c.y < 0.f)
	{
		c.y *= -1.f;
		neg = true;
	}

	std::string info = "Julia" + m_DebugInfo.getString() + "Complex Parameter: C = " + std::to_string(c.x) + (neg ? " - i" : " + i") + std::to_string(c.y);
	m_DebugInfo.setString(info);

	target.draw(m_DebugInfo);
}