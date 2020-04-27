#include "CheckBox.h"

CheckBox::CheckBox(sf::Vector2f t_pos, std::string t_text, bool t_startEnabled) :
	m_enabled(t_startEnabled), m_highlighted(false)
{


}

void CheckBox::onClick()
{
	if (nullptr != m_onClick)
	{
		if (m_enabled)
		{
			m_enabled = false;
		}
		else
		{
			m_enabled = true;
		}
		changeTexture();
		m_onClick();
    }
}
/// <summary>
/// Initiailes the buttons directions
/// </summary>
/// <param name="t_up"></param>
/// <param name="t_down"></param>
/// <param name="t_left"></param>
/// <param name="t_right"></param>
void CheckBox::initialise(GUI* t_up, GUI* t_down, GUI* t_left, GUI* t_right)
{
	m_up = t_up;
	m_down = t_down;
	m_left =t_left;
	m_right = t_right;
}
/// <summary>
/// set up for function call backs 
/// </summary>
/// <param name="t_onClick"></param>
void CheckBox::setOnClick(void(*t_onClick)())
{
	m_onClick = std::bind(*t_onClick);
}
/// <summary>
/// switches the selected button to whatever button is to the left
/// </summary>
/// <param name="t_selectedButton"></param>
void CheckBox::left(GUI** t_selectedButton)
{
	if (nullptr != m_left)
	{
		highlighted();
		m_left->highlighted();
		*t_selectedButton = m_left;
	}
}
/// <summary>
/// switches the selected button to whatever button is to the right
/// </summary>
/// <param name="t_selectedButton"></param>
void CheckBox::right(GUI** t_selectedButton)
{
	if (nullptr != m_right)
	{
		highlighted();
		m_right->highlighted();
		*t_selectedButton = m_right;
	}
}
/// <summary>
/// switches the selected button to whatever button is to the up
/// </summary>
/// <param name="t_selectedButton"></param>
void CheckBox::up(GUI** t_selectedButton)
{
	if (nullptr != m_up)
	{
		highlighted();
		m_up->highlighted();
		*t_selectedButton = m_up;
	}
}
/// <summary>
/// switches the selected button to whatever button is to the down
/// </summary>
/// <param name="t_selectedButton"></param>
void CheckBox::down(GUI** t_selectedButton)
{
	if (nullptr != m_down)
	{
		highlighted();
		m_down->highlighted();
		*t_selectedButton = m_down;
	}
}
/// <summary>
/// sets the texture to a highlighted texture
/// </summary>
void CheckBox::highlighted()
{
	if (m_highlighted)
	{
		
		m_highlighted = false;
	}
	else
	{
		m_highlighted = true;
	}

	if (m_enabled && m_highlighted)
	{
		m_enabled = false;

	}
	else if (!m_enabled && m_highlighted)
	{
		m_enabled = true;
	}
	if (m_enabled && !m_highlighted)
	{
		m_enabled = false;
	}
	else if (!m_enabled && !m_highlighted)
	{
		m_enabled = true;
	}

}
/// <summary>
/// changes the texture 
/// </summary>
void CheckBox::changeTexture()
{
	if (m_enabled)
	{
		m_body.setTexture(m_enabledTexture);
	}
	else
	{
		m_body.setTexture(m_notEnabledTexture);
	}
	if (m_highlighted)
	{
		m_body.setColor(sf::Color::Green);

	}

	else
	{

		m_body.setColor(sf::Color::Red);

	}
}
/// <summary>
/// Draws the button and tex
/// </summary>
/// <param name="t_win"></param>
void CheckBox::drawButton(sf::RenderWindow& t_win)
{
	t_win.draw(m_body);
	t_win.draw(m_buttonText);
}
