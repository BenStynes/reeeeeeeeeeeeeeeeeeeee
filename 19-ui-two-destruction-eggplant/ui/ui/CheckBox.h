#pragma once
#include "GUI.h"

class CheckBox :
	public GUI
{
public:
	CheckBox() = delete;
	CheckBox(sf::Vector2f t_pos, std::string t_text, bool t_startEnabled);
private:
	sf::Texture m_enabledTexture;
	sf::Texture m_notEnabledTexture;
	bool m_enabled;
	bool m_highlighted;

protected:
	std::function<void()> m_onClick{ nullptr };//function used when on click is called
	virtual void onClick() override;
	virtual void initialise(GUI* t_up,
							GUI* t_down,
							GUI* t_left,
							GUI* t_right) override;//sets up 4 buttons that the button goes to
	virtual void setOnClick(void(*t_onClick)()) override;//sets up the on click function
	virtual void left(GUI** t_selectedButton) override;//switches the selected button to whatever button is to the left
	virtual void right(GUI** t_selectedButton) override;//switches the selected button to whatever button is to the right
	virtual void up(GUI** t_selectedButton) override;//switches the selected button to whatever button is to the top
	virtual void down(GUI** t_selectedButton) override;//switches the selected button to whatever button is to the bottom
	virtual void highlighted() override;//sets the texture to a highlighted texture
	void setLeft(GUI* t_button) { m_left = t_button; };//sets the left button
	void setRight(GUI* t_button) { m_right = t_button; };//sets the right button
	void setUp(GUI* t_button) { m_up = t_button; };//sets the up button
	void setDown(GUI* t_button) { m_down = t_button; };//sets the down button
	void changeTexture();
	void drawButton(sf::RenderWindow &t_win);

};

