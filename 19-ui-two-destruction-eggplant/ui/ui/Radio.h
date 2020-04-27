#ifndef RADIO_H
#define RADIO_H

#include "GUI.h"
#include <typeinfo>

class Radio :
	public GUI
{
public:
	Radio() = delete; //don't use the default constructor
	Radio(std::string t_string, sf::Vector2f t_position, bool t_enabled, const int t_MAX_RADIOS, Radio* t_radioArray[]);
private:
	sf::IntRect m_highlightEnabledRect; // button is highlighted, and enabled
	sf::IntRect m_highlightDisabledRect; // button is highlighted, and disabled
	sf::IntRect m_enabledRect; // button is not highlighted, and enabled
	sf::IntRect m_disabledRect; // button is not highlighted, and disabled

	bool m_enabled;
	bool m_highlighted{ false };

	Radio** m_radioArray;

public:
	virtual void onClick() override;
	virtual void initialise(GUI* t_up,
							GUI* t_down,
							GUI* t_left,
							GUI* t_right) override;//sets up 4 buttons that the button goes to
	virtual void setOnClick(void(*t_onClick)()) override;//sets up the on click function
	virtual void left(GUI** t_selectedButton) override;//switches the selected button to whatever button is to the left
	virtual void right(GUI** t_selectedButton)override;//switches the selected button to whatever button is to the right
	virtual void up(GUI** t_selectedButton) override;//switches the selected button to whatever button is to the top
	virtual void down(GUI** t_selectedButton) override;//switches the selected button to whatever button is to the bottom
	virtual void highlighted() override;//sets the texture to a highlighted texture
	void disable(); // disable this button if called
	void makeDisabled();
	// make all other radio buttons disabled if this radio button is enabled
	void changeTexture();
	void drawButton(sf::RenderWindow& t_window);
	bool getEnabled();

	const int c_MAX_RADIO_BUTTONS;
};

#endif