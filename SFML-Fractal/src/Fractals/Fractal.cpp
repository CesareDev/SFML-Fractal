#include "Fractal.h"
#include <SFML/Window/Keyboard.hpp>

Fractal::Fractal()
{
}

Fractal::~Fractal()
{
}

void Fractal::Init(const ResourceManager& resourceManager, sf::Vector2u windowSize)
{
	m_WindowSize = windowSize;
	m_Rect.setSize(sf::Vector2f(m_WindowSize.x, m_WindowSize.y));
	m_States.shader = &m_FractalShader;
	
	m_Scale = 1.f;
	m_CameraPos = { 0.f, 0.f };

	sf::Vector2f offset =
	{
		m_Rect.getPosition().x,
		m_WindowSize.y - m_Rect.getPosition().y - m_Rect.getSize().y
	};

	//									Ww
	//   +----------------------------------------------------------------+
	//   |          gl_FragCoord.x                                        |
	//   |<---------------------------------->|							  |
	//   |						  (Xr,Yr) 	  |							  |
	//   |						     |        |      					  |
	//   |							 +->+------------------+			  |
	//   |								|	  			   |		      | Hw
	//   |		|---------------------->|-----*		       | Hr			  |
	//   |		|						|	  |			   |			  |
	//   |		|						+------------------+			  |
	//   |		| gl_FragCoord.y			  		|					  |
	//   |		|									| Hw - Yr - Hr		  |
	//   |		|									|					  |
	//   +----------------------------------------------------------------+

	m_FractalShader.setUniform("u_ViewportSize", m_Rect.getSize());
	m_FractalShader.setUniform("u_ViewportOffset", offset);
	m_FractalShader.setUniform("u_Scale", m_Scale);
	m_FractalShader.setUniform("u_CameraPosition", m_CameraPos);

	m_DebugInfo.setFont(resourceManager.GetFont());
	m_DebugInfo.setCharacterSize(15);
	m_DebugInfo.setPosition(m_Rect.getPosition().x + 4.f, m_Rect.getPosition().y + 4.f);
	m_DebugInfo.setFillColor(sf::Color::Red);
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
		+ ", " + std::to_string(imgEnd) + "]\n";

	m_DebugInfo.setString(info);

	target.draw(m_Rect, m_States);
}

void Fractal::HandleZoom(float dt)
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