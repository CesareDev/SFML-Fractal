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
	m_WindowSize = windowSize;
	m_Scale = 1.f;
	m_Rect.setSize(sf::Vector2f(m_WindowSize));
	m_FractalShader.loadFromFile("res/shaders/julia.glsl", sf::Shader::Fragment);
	m_States.shader = &m_FractalShader;

	m_FractalShader.setUniform("u_WinSize", sf::Glsl::Vec2(m_WindowSize));
	m_FractalShader.setUniform("u_Scale", m_Scale);
	m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));

	m_Font.loadFromFile("res/font/PixeloidMono-d94EV.ttf");
	m_DebugInfo.setFont(m_Font);
	m_DebugInfo.setCharacterSize(15);
	m_DebugInfo.setPosition(4.f, 4.f);
}

void Julia::UpdateAndRender(float dt, sf::RenderTarget& target)
{	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_MousePos = sf::Vector2f(sf::Mouse::getPosition((sf::RenderWindow&)target));
		m_FractalShader.setUniform("u_MousePosition", m_MousePos);
	}

	std::string info = "Julia\nInfo:\n";
	info += "Scale = " + std::to_string(m_Scale) + "\n\n";

	float ratio = m_WindowSize.x / (float)m_WindowSize.y;
	float imgStart = (-1.f / m_Scale);
	float imgEnd = (1.f / m_Scale);
	float realStart = (imgStart * ratio);
	float realEnd = (imgEnd * ratio);

	imgStart += m_CameraPos.y;
	imgEnd += m_CameraPos.y;
	realStart += m_CameraPos.x;
	realEnd += m_CameraPos.x;

	info += "Complex Range:\nReal = [" + std::to_string(realStart)
		+ ", " + std::to_string(realEnd) + "]\n" +
		"Img = [" + std::to_string(imgStart)
		+ ", " + std::to_string(imgEnd) + "]\n\n";

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

	info += "Complex Parameter: C = " + std::to_string(c.x) + (neg ? " - i" : " + i") + std::to_string(c.y);

	m_DebugInfo.setString(info);

	target.draw(m_Rect, m_States);
	target.draw(m_DebugInfo);
}