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
}

void Julia::UpdateAndRender(float dt, sf::RenderTarget& target)
{	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i pos = sf::Mouse::getPosition((sf::RenderWindow&)target);
		m_FractalShader.setUniform("u_MousePosition", sf::Glsl::Vec2(pos));
	}

	target.draw(m_Rect, m_States);
}

void Julia::ResetVariables()
{
	m_CameraPos = { 0.f, 0.f };
	m_Scale = 1.f;

	m_FractalShader.setUniform("u_WinSize", sf::Glsl::Vec2(m_WindowSize));
	m_FractalShader.setUniform("u_Scale", m_Scale);
	m_FractalShader.setUniform("u_CameraPosition", sf::Glsl::Vec2(m_CameraPos));
}
