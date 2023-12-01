#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Text.hpp>

class Fractal
{
public:

	Fractal();
	virtual ~Fractal();

	virtual void Init(sf::Vector2u windowSize) = 0;
	virtual void UpdateAndRender(float dt, sf::RenderTarget& target) = 0;

	void HandleZoom(float dt);
	void HandleCamera(float dt);

protected:

	sf::RectangleShape m_Rect;
	sf::Vector2u m_WindowSize;
	sf::Shader m_FractalShader;
	sf::RenderStates m_States;

	sf::Vector2f m_CameraPos;
	float m_Scale;

	sf::Font m_Font;
	sf::Text m_DebugInfo;
};

