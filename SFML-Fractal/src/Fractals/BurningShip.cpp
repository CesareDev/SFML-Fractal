#include "BurningShip.h"

BurningShip::BurningShip()
{
}

BurningShip::~BurningShip()
{
}

void BurningShip::Init(sf::Vector2u windowSize)
{
	m_WindowSize = windowSize;
	m_Scale = 1.f;
	m_Rect.setSize(sf::Vector2f(m_WindowSize));
	m_FractalShader.loadFromFile("res/shaders/burningship.glsl", sf::Shader::Fragment);
	m_States.shader = &m_FractalShader;

	m_FractalShader.setUniform("u_WinSize", sf::Glsl::Vec2(m_WindowSize));
	m_FractalShader.setUniform("u_Scale", m_Scale);
	m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));

	m_Font.loadFromFile("res/font/PixeloidMono-d94EV.ttf");
	m_DebugInfo.setFont(m_Font);
	m_DebugInfo.setCharacterSize(15);
	m_DebugInfo.setPosition(4.f, 4.f);
}

void BurningShip::UpdateAndRender(float dt, sf::RenderTarget& target)
{
	std::string info = "Burning Ship\nInfo:\n";
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
		+ ", " + std::to_string(imgEnd) + "]";

	m_DebugInfo.setString(info);

	target.draw(m_Rect, m_States);
	target.draw(m_DebugInfo);
}
