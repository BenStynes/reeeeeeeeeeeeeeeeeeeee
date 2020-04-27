#include "Slider.h"

Slider::Slider() : m_minValue{ 0.0f }, m_maxValue{ 1.0f }, m_valueToChange{ nullptr }, m_currentValue{ 0.0f }
{/*
	m_up = this;
	m_down = this;
	m_left = this;
	m_right = this;*/
	m_textString = "Default";
	if (!m_font.loadFromFile("ASSETS//FONTS//ariblk.ttf"))
	{
		std::cerr << "problem loading ASSETS//FONTS//ariblk.ttf" << std::endl;
	}
	m_buttonText.setFont(m_font);
	m_buttonText.setString(m_textString);
	m_buttonText.setCharacterSize(28);
	m_buttonText.setFillColor(sf::Color::White);
	m_buttonText.setPosition(sf::Vector2f{0.0f,0.0f} +sf::Vector2f{ 0, m_buttonText.getGlobalBounds().height / 2 });
}

Slider::Slider(sf::Vector2f t_position, std::string t_text) : m_minValue{ 0.0f },
															  m_maxValue{ 1.0f }, 
															  m_currentValue{ 1.0f },
															  m_valueToChange{ nullptr }
{/*
	m_up = this;
	m_down = this;
	m_left = this;
	m_right = this;*/

	if (!m_buttonTexture.loadFromFile("ASSETS/IMAGES/Slider.png"))
	{
		std::cerr << "problem loading ASSETS/IMAGES/Slider.png" << std::endl;
	}

	m_sliderBar.setTexture(m_buttonTexture);
	m_movingBar.setTexture(m_buttonTexture);

	m_sliderBar.setTextureRect(sf::IntRect(120, 0, 72, 14));
	m_movingBar.setTextureRect(sf::IntRect(96, 0, 24, 28));


	m_sliderBar.setScale(2.0f, 1.0f);

	m_sliderBar.setPosition(t_position);
	m_movingBar.setPosition(m_sliderBar.getPosition() + sf::Vector2f(m_sliderBar.getGlobalBounds().width * m_currentValue,
		                   0.0f));

	if (!m_font.loadFromFile("ASSETS//FONTS//ariblk.ttf"))
	{
		std::cerr << "problem loading ASSETS//FONTS//ariblk.ttf" << std::endl;
	}

	// position the text first
	m_textString = t_text;
	m_buttonText.setFont(m_font);
	m_buttonText.setString(t_text);
	m_buttonText.setCharacterSize(36);
	m_buttonText.setFillColor(sf::Color::Red);
	m_buttonText.setPosition(t_position + sf::Vector2f{ 0, m_buttonText.getGlobalBounds().height});

	m_highlighted = false;
}

/// <summary>
/// Set up Button to point to any other buttons for movement, if they exist.
/// </summary>
/// <param name="t_up">Button Above</param>
/// <param name="t_down">Button Below</param>
/// <param name="t_left">Button on Left</param>
/// <param name="t_right">Button on Right</param>
void Slider::initialise(GUI* t_up, GUI* t_down, GUI* t_left, GUI* t_right)
{
	m_up = t_up;
	m_down = t_down;
	m_left = t_left;
	m_right = t_right;
}

/// <summary>
/// Set up for function callbacks
/// </summary>
/// <param name="t_onClick">Function to refer to</param>
void Slider::setOnClick(void(*t_onClick)())
{
	std::bind(m_onClick, t_onClick);
}

void Slider::onClick()
{
	if (nullptr != m_onClick)
	{
		m_onClick;
	}
}

void Slider::left(GUI** t_selectedButton)
{

	if (m_currentValue <= m_maxValue
		&& m_currentValue > m_minValue)
	{
		m_currentValue -= 0.1f;	
	}
	else if (m_currentValue == m_minValue)
	{
		if (m_left != nullptr)
		{
			*t_selectedButton = m_left;
		}
	}
}

void Slider::right(GUI** t_selectedButton)
{

	if (m_currentValue < m_maxValue
		&& m_currentValue >= m_minValue - 0.1f)
	{
		m_currentValue += 0.1f;
	}
	else if (m_currentValue == m_maxValue)
	{
		if (m_right != nullptr)
		{
			*t_selectedButton = m_right;
		}
	}
}

void Slider::up(GUI** t_selectedButton)
{
	if (nullptr != m_up)
	{
		highlighted();
		m_up->highlighted();
		*t_selectedButton = m_up;
	}
}

void Slider::down(GUI** t_selectedButton)
{
	if (nullptr != m_down)
	{
		highlighted();
		m_down->highlighted();
		*t_selectedButton = m_down;
	}
}

void Slider::highlighted()
{
	if (m_highlighted)
	{
		m_highlighted = false;
	}
	else
	{
		m_highlighted = true;
	}

	if (m_highlighted)
	{
		m_sliderBar.setTextureRect(sf::IntRect(0, 0, 70, 14));
		m_movingBar.setTextureRect(sf::IntRect(72, 0, 24, 28));
	}
	else
	{
		m_sliderBar.setTextureRect(sf::IntRect(120, 0, 72, 14));
		m_movingBar.setTextureRect(sf::IntRect(96, 0, 24, 28));
	}
}

void Slider::drawButton(sf::RenderWindow& t_window)
{
	m_movingBar.setPosition(m_sliderBar.getPosition() + sf::Vector2f(m_currentValue * m_sliderBar.getGlobalBounds().width,
		0.0f));

	t_window.draw(m_sliderBar);
	t_window.draw(m_movingBar);
	t_window.draw(m_buttonText);
}
