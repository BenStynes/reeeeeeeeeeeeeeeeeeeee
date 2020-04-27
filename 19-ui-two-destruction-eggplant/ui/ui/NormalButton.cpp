#include "NormalButton.h"

NormalButton::NormalButton(sf::Vector2f t_pos, std::string t_text)
{
	if (!m_font.loadFromFile("ASSETS//FONTS//ariblk.ttf"))
	{
		//error loading font file
	}
	GUI::m_text = t_text;

	m_buttonsText.setFont(m_font);
	m_buttonsText.setCharacterSize(28);
	m_buttonsText.setString(m_text);
	m_buttonsText.setFillColor(sf::Color::White);

	m_highlighted = false;

	m_body.setTexture(m_normal);

	float scale{ 1.0f };

	while (m_buttonsText.getGlobalBounds().width > m_body.getGlobalBounds().width)
	{
		scale += 0.1f;
		m_body.setScale(scale, 1.0f);
	}

	if (!m_normal.loadFromFile("ASSETS//IMAGES//buttonClicked.png"))
	{
		// error
	}
	if (!m_hovered.loadFromFile("ASSETS//IMAGES//hoveringOverButtons.png"))
	{
		// error
	}
	m_body.setPosition(t_pos.x - m_body.getGlobalBounds().width / 2, t_pos.y);
	m_buttonsText.setPosition(m_body.getPosition() + sf::Vector2f{ 0, m_buttonsText.getGlobalBounds().height / 1.5f });
}

void NormalButton::onClick()
{
	if (nullptr != m_onClick)
	{
		m_onClick();
	}
}

void NormalButton::initialise(GUI* t_up, GUI* t_down, GUI* t_left, GUI* t_right)
{
	m_up = t_up;
	m_down = t_down;
	m_left = t_left;
	m_right = t_right;
}

void NormalButton::setOnClick(void(*t_onClick)())
{
	m_onClick = std::bind(*t_onClick);
}

void NormalButton::left(GUI** t_selectedButton)
{
	if(nullptr != m_left)
	{
		highlighted();
		m_left->highlighted();
		*t_selectedButton = m_left;
	}
}

void NormalButton::right(GUI** t_selectedButton)
{
	if (nullptr != m_right)
	{
		highlighted();
		m_right->highlighted();
		*t_selectedButton = m_right;
	}
}

void NormalButton::up(GUI** t_selectedButton)
{
	if (nullptr != m_up)
	{
		highlighted();
		m_up->highlighted();
		*t_selectedButton = m_up;
	}
}

void NormalButton::down(GUI** t_selectedButton)
{
	if (nullptr != m_down)
	{
		highlighted();
		m_down->highlighted();
		*t_selectedButton = m_down;
	}
}

void NormalButton::highlighted()
{
	if (m_highlighted)
	{
		m_highlighted = false;
	}

	else
	{
		m_highlighted = true;
	}


	/// <summary>
	/// switches textures around
	/// </summary>
	if (m_highlighted)
	{
		m_body.setTexture(m_hovered);
	}

	else
	{
		m_body.setTexture(m_normal);
	}
}

void NormalButton::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	t_window.draw(m_buttonsText);

}
