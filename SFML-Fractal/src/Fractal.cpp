#include "Fractal.h"
#include <SFML/Window/Keyboard.hpp>

Fractal::Fractal()
{
}

Fractal::~Fractal()
{
}

void Fractal::HandleZoom(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_Scale += 10.f * dt;
		m_FractalShader.setUniform("u_Scale", m_Scale);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_Scale -= 10.f * dt;
		m_FractalShader.setUniform("u_Scale", m_Scale);
	}
}

void Fractal::HandleCamera(float dt)
{
	float offset = 1.f / m_Scale;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_CameraPos.y += offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CameraPos.x -= offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_CameraPos.y -= offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CameraPos.x += offset * dt;
		m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));
	}
}

void Fractal::ResetVariables()
{
	m_CameraPos = { 0.f, 0.f };
	m_Scale = 1.f;

	m_FractalShader.setUniform("u_WinSize", sf::Glsl::Vec2(m_WindowSize));
	m_FractalShader.setUniform("u_Scale", m_Scale);
	m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));
}
