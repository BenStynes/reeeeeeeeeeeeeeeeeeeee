#include "Radio.h"

Radio::Radio(std::string t_string, sf::Vector2f t_position, bool t_enabled, const int t_MAX_RADIOS, Radio* t_radioArray[]) :
	c_MAX_RADIO_BUTTONS(t_MAX_RADIOS),
	m_enabled{ t_enabled }, m_disabledRect(0, 0, 158, 168), m_highlightDisabledRect(158, 0, 158, 168),
	m_enabledRect(316, 0, 158, 168), m_highlightEnabledRect(473, 0, 158, 168), m_radioArray(t_radioArray)
{
}

void Radio::onClick()
{
	if (!m_enabled) // make sure this radio button isn't already enabled
	{				// if it's already enabled, we don't need to make changes.
		if (nullptr != m_onClick)
		{
			makeDisabled(); // disable any other buttons
			m_enabled = true; // say this button is enabled
			changeTexture(); // visually reflect the change

			m_onClick(); // call the function associated with this button
		}
	}
}

/// <summary>
/// initializes the four buttons to the left, right, top and bottom of the current button
/// </summary>
/// <param name="t_up">button above the current button</param>
/// <param name="t_down">button below the current button</param>
/// <param name="t_left">button to the left of the current button</param>
/// <param name="t_right">button to the right of the current button</param>
void Radio::initialise(GUI* t_up, GUI* t_down, GUI* t_left, GUI* t_right)
{
	m_up = t_up;
	m_down = t_down;
	m_left = t_left;
	m_right = t_right;
}

/// <summary>
/// sets the function that on click refers to 
/// </summary>
/// <param name="t_onClick">function to use for the on click</param>
void Radio::setOnClick(void(*t_onClick)())
{
	m_onClick = std::bind(*t_onClick);
}

/// <summary>
/// changes the currently selected button to the button that is tot the left of this button
/// </summary>
/// <param name="t_selectedButton">gui to store what the currently selected button is</param>
void Radio::left(GUI** t_selectedButton)
{
	if (nullptr != m_left)
	{
		m_highlighted = false;

		if (m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_enabledRect);
		}
		else if (!m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_disabledRect);
		}

		m_left->highlighted();
		*t_selectedButton = m_left;
	}
}

/// <summary>
/// changes the currently selected button to the button that is to the right of this button
/// </summary>
/// <param name="t_selectedButton">gui to store what the currently selected button is</param>
void Radio::right(GUI** t_selectedButton)
{
	if (nullptr != m_right)
	{
		m_highlighted = false;

		if (m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_enabledRect);
		}
		else if (!m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_disabledRect);
		}

		m_right->highlighted();
		*t_selectedButton = m_right;
	}
}

/// <summary>
/// changes the currently selected button to the button that is above this button
/// </summary>
/// <param name="t_selectedButton">gui to store what the currently selected button is</param>
void Radio::up(GUI** t_selectedButton)
{
	if (nullptr != m_up)
	{
		m_highlighted = false;

		if (m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_enabledRect);
		}
		else if (!m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_disabledRect);
		}

		m_up->highlighted();
		*t_selectedButton = m_up;
	}
}

/// <summary>
/// changes the currently selected button to the button that is below this button
/// </summary>
/// <param name="t_selectedButton">gui to store what the currently selected button is</param>
void Radio::down(GUI** t_selectedButton)
{
	if (nullptr != m_down)
	{
		m_highlighted = false;

		if (m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_enabledRect);
		}
		else if (!m_enabled && !m_highlighted)
		{
			m_body.setTextureRect(m_disabledRect);
		}

		m_down->highlighted();
		*t_selectedButton = m_down;
	}
}

/// <summary>
/// changes the texture to show that the button has been highlighted
/// </summary>
void Radio::highlighted()
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
		m_body.setTextureRect(m_highlightEnabledRect);
	}
	else if (!m_enabled && m_highlighted)
	{
		m_body.setTextureRect(m_highlightDisabledRect);
	}
	else if (m_enabled && !m_highlighted)
	{
		m_body.setTextureRect(m_enabledRect);
	}
	else if (!m_enabled && !m_highlighted)
	{
		m_body.setTextureRect(m_disabledRect);
	}
}

/// <summary>
/// Go through Radio Array and disable any other Radio buttons, since this one wants to be enabled
/// </summary>
void Radio::disable()
{

	m_enabled = false;
	m_body.setTextureRect(m_disabledRect);

}

void Radio::makeDisabled()
{
	for (int index = 0; index < c_MAX_RADIO_BUTTONS; index++)
	{
		if (m_radioArray[index] != this) // make sure this isnt the same radio button in memory
		{
			m_radioArray[index]->disable();
		}
	}
}

/// <summary>
/// Changes the Texture to reflect whether or not the radio button is currently enabled/disabled
/// </summary>
void Radio::changeTexture()
{

	// We don't need to check to see if this button is highlighted,
	// as the only way this function can be called is on a highlighted button.
	// because of this, we only need to check if this button was enabled or disabled

	if (m_enabled)
	{
		m_body.setTextureRect(m_highlightEnabledRect);
	}
	else
	{
		m_body.setTextureRect(m_highlightDisabledRect);
	}
}


/// <summary>
/// draws the radio button
/// </summary>
/// <param name="t_window">target render window</param>
void Radio::drawButton(sf::RenderWindow& t_window)
{
	t_window.draw(m_bodyLeft);
	t_window.draw(m_body);
	t_window.draw(m_bodyRight);
	t_window.draw(m_buttonText);
}

bool Radio::getEnabled()
{
	return m_enabled;
}
