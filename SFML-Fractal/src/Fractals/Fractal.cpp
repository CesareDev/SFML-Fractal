#include "Fractal.h"
#include <SFML/Window/Keyboard.hpp>

Fractal::Fractal()
{
}

Fractal::~Fractal()
{
}

void Fractal::Init(sf::Vector2u windowSize)
{
	m_WindowSize = windowSize;
	m_Rect.setSize(sf::Vector2f(m_WindowSize));
	m_States.shader = &m_FractalShader;
	
	m_Scale = 1.f;
	m_CameraPos = { 0.f, 0.f };

	m_FractalShader.setUniform("u_WinSize", sf::Glsl::Vec2(m_WindowSize));
	m_FractalShader.setUniform("u_Scale", m_Scale);
	m_FractalShader.setUniform("u_CameraPosition", m_CameraPos);

	m_RedFrequencyPhase = { 0.1f, 1.f };
	m_GreenFrequencyPhase = { 0.1f, 2.f };
	m_BlueFrequencyPhase = { 0.1f, 3.f };

	m_FractalShader.setUniform("u_RedFrequencyPhase", m_RedFrequencyPhase);
	m_FractalShader.setUniform("u_GreenFrequencyPhase", m_GreenFrequencyPhase);
	m_FractalShader.setUniform("u_BlueFrequencyPhase", m_BlueFrequencyPhase);

	m_Font.loadFromFile("res/font/PixeloidMono-d94EV.ttf");
	m_DebugInfo.setFont(m_Font);
	m_DebugInfo.setCharacterSize(15);
	m_DebugInfo.setPosition(4.f, 4.f);
	m_DebugInfo.setFillColor(sf::Color::Black);
}

void Fractal::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	std::string info = "\nInfo:\n";
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
		+ ", " + std::to_string(imgEnd) + "]\n\n" +
		"Coloring formula : channel = sin(f * steps + p)\n" +
		"Red f = " + std::to_string(m_RedFrequencyPhase.x) + ", p = " + std::to_string(m_RedFrequencyPhase.y) + "\n" +
		"Green f = " + std::to_string(m_GreenFrequencyPhase.x) + ", p = " + std::to_string(m_GreenFrequencyPhase.y) + "\n" +
		"Blue f = " + std::to_string(m_BlueFrequencyPhase.x) + ", p = " + std::to_string(m_BlueFrequencyPhase.y) + "\n\n";

	m_DebugInfo.setString(info);

	target.draw(m_Rect, m_States);
}

void Fractal::HandleZoom(float dt)
{
	bool r = sf::Keyboard::isKeyPressed(sf::Keyboard::R);
	bool g = sf::Keyboard::isKeyPressed(sf::Keyboard::G);
	bool b = sf::Keyboard::isKeyPressed(sf::Keyboard::B);

	if (!r && !g && !b)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_Scale *= 1.1f;
			m_FractalShader.setUniform("u_Scale", m_Scale);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_Scale /= 1.1f;
			m_FractalShader.setUniform("u_Scale", m_Scale);
		}
	}
}

void Fractal::HandleCamera(float dt)
{
	float offset = 1.f / m_Scale;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_CameraPos.y += offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", m_CameraPos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CameraPos.x -= offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", m_CameraPos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_CameraPos.y -= offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", m_CameraPos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CameraPos.x += offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", m_CameraPos);
	}
}

void Fractal::HandleColor(float dt)
{	
	//RED CHANNEL
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		//FREQUENCY
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_RedFrequencyPhase.x += 0.05f * dt;
				m_FractalShader.setUniform("u_RedFrequencyPhase", m_RedFrequencyPhase);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_RedFrequencyPhase.x -= 0.05f * dt;
				m_FractalShader.setUniform("u_RedFrequencyPhase", m_RedFrequencyPhase);
			}
		}
		//PHASE
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_RedFrequencyPhase.y += 0.5f * dt;
				m_FractalShader.setUniform("u_RedFrequencyPhase", m_RedFrequencyPhase);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_RedFrequencyPhase.y -= 0.5f * dt;
				m_FractalShader.setUniform("u_RedFrequencyPhase", m_RedFrequencyPhase);
			}
		}
	}
	//GREEN CHANNEL
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		//FREQUENCY
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_GreenFrequencyPhase.x += 0.05f * dt;
				m_FractalShader.setUniform("u_GreenFrequencyPhase", m_GreenFrequencyPhase);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_GreenFrequencyPhase.x -= 0.05f * dt;
				m_FractalShader.setUniform("u_GreenFrequencyPhase", m_GreenFrequencyPhase);
			}
		}
		//PHASE
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_GreenFrequencyPhase.y += 0.5f * dt;
				m_FractalShader.setUniform("u_GreenFrequencyPhase", m_GreenFrequencyPhase);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_GreenFrequencyPhase.y -= 0.5f * dt;
				m_FractalShader.setUniform("u_GreenFrequencyPhase", m_GreenFrequencyPhase);
			}
		}
	}
	//BLUE CHANNEL
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		//FREQUENCY
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_BlueFrequencyPhase.x += 0.05f * dt;
				m_FractalShader.setUniform("u_BlueFrequencyPhase", m_BlueFrequencyPhase);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_BlueFrequencyPhase.x -= 0.05f * dt;
				m_FractalShader.setUniform("u_BlueFrequencyPhase", m_BlueFrequencyPhase);
			}
		}
		//PHASE
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_BlueFrequencyPhase.y += 0.5f * dt;
				m_FractalShader.setUniform("u_BlueFrequencyPhase", m_BlueFrequencyPhase);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_BlueFrequencyPhase.y -= 0.5f * dt;
				m_FractalShader.setUniform("u_BlueFrequencyPhase", m_BlueFrequencyPhase);
			}
		}
	}
}
