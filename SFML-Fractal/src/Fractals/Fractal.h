#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Core/ResourceManager.h"

class Fractal
{
public:

	Fractal();
	virtual ~Fractal();

	virtual void Init(const ResourceManager& resourceManager, sf::Vector2u windowSize);
	virtual void UpdateAndRender(float dt, sf::RenderTarget& target);

	void HandleZoom(float dt);
	void HandleCamera(float dt);
	void HandleColor(float dt);

protected:

	sf::RectangleShape m_Rect;
	sf::Shader m_FractalShader;
	sf::RenderStates m_States;

	sf::Vector2f m_RedFrequencyPhase;
	sf::Vector2f m_GreenFrequencyPhase;
	sf::Vector2f m_BlueFrequencyPhase;
	sf::Vector2u m_WindowSize;
	sf::Vector2f m_CameraPos;
	float m_Scale;

	sf::Text m_DebugInfo;
};

